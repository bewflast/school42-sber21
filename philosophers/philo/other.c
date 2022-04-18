/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:13:57 by lwendi            #+#    #+#             */
/*   Updated: 2022/04/18 22:05:37 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	if (!(str[i] >= '0' && str [i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str [i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * n);
}

int	ft_validate(int argc, char **argv, int *target)
{
	int	i;
	int	tmp;

	i = 0;
	*(target + 4) = -1;
	if (argc < 5 || argc > 6)
	{
		write(1, "Too few/many arguments\n", 23);
		return (0);
	}
	while (++i <= argc - 1)
	{
		tmp = ft_atoi(*(argv + i));
		if (tmp < 0)
		{
			write(1, "Incorrect arg\n", 14);
			return (0);
		}
		*(target + i - 1) = tmp;
	}
	return (1);
}

int	check_state(t_glob *info, int eat_count)
{
	int	res;

	res = 1;
	pthread_mutex_lock(&info->mut);
	if (!info->status)
		res = 0;
	pthread_mutex_unlock(&info->mut);
	return (res && (eat_count != info->num_to_eat));
}

void	start_philos(t_glob *global)
{
	int	i;
	int	num;

	num = global->quantity;
	i = 1;
	while (i < num)
	{
		pthread_create(global->philosophers[i]->thr, NULL, \
		live, (void *)global->philosophers[i]);
		usleep(20);
		i += 2;
	}
	i = 0;
	while (i < num)
	{
		pthread_create(global->philosophers[i]->thr, NULL, \
		live, (void *)global->philosophers[i]);
		usleep(20);
		i += 2;
	}
}

void	chmo(t_glob *info)
{
	int		i;
	time_t	lm;

	while (1)
	{
		i = -1;
		if (pokushali(info))
			return ;
		while (++i < info->quantity)
		{
			pthread_mutex_lock(&info->mut);
			lm = info->philosophers[i]->last_meal;
			pthread_mutex_unlock(&info->mut);
			if (get_ts(&info->start) - lm > info->ttd)
			{
				pthread_mutex_lock(&info->mut);
				info->status = 0;
				pthread_mutex_unlock(&info->forks[info->\
				philosophers[i]->fork_left_pos]);
				printf("\n[%ld] %d died", get_ts(&info->start), i + 1);
				pthread_mutex_unlock(&info->mut);
				return ;
			}
		}
	}
}
