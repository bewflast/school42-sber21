/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:14:18 by lwendi            #+#    #+#             */
/*   Updated: 2022/04/18 21:40:20 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pokushali(t_glob *info)
{
	int	i;
	int	vsego_pokushali;

	vsego_pokushali = 0;
	i = -1;
	while (++i < info->quantity)
	{
		pthread_mutex_lock(&info->mut);
		vsego_pokushali += info->philosophers[i]->status;
		pthread_mutex_unlock(&info->mut);
	}
	return (vsego_pokushali == info->quantity);
}

time_t	get_ts(struct timeval *start)
{
	struct timeval	cur;
	int				dms;
	int				dmcs;

	gettimeofday(&cur, NULL);
	dms = cur.tv_sec - start->tv_sec;
	dmcs = cur.tv_usec - start->tv_usec;
	if (dmcs < 0)
	{
		dms--;
		dmcs += 1000000;
	}
	return (dms * 1000 + dmcs / 1000);
}

t_phil	*new_philosopher(void *glob, int id)
{
	t_phil	*p;
	t_glob	*g;

	g = (t_glob *)glob;
	p = (t_phil *)malloc(sizeof(t_phil));
	p->thr = (pthread_t *)malloc(sizeof(pthread_t));
	p->ident = id;
	p->glob = (t_glob *)g;
	p->cur_state = 2;
	p->status = 0;
	p->eat_count = 0;
	if (p->ident == 1)
		p->fork_left_pos = g->quantity - 1;
	else
		p->fork_left_pos = p->ident - 2;
	p->fork_right_pos = p->ident - 1;
	p->last_meal = 0;
	return (p);
}

t_glob	*init_global(int *args, int num)
{
	t_glob			*global;
	int				i;
	unsigned long	start;

	i = -1;
	global = (t_glob *)malloc(sizeof(t_glob));
	global->quantity = num;
	global->ttd = args[1];
	global->tte = args[2];
	global->tts = args[3];
	global->num_to_eat = args[4];
	global->status = 1;
	global->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	global->philosophers = (t_phil **)malloc(sizeof(t_phil) * num);
	while (++i < num)
		global->philosophers[i] = new_philosopher(global, i + 1);
	i = -1;
	while (++i < num)
		pthread_mutex_init(&global->forks[i], NULL);
	pthread_mutex_init(&global->mut, NULL);
	gettimeofday(&global->start, NULL);
	start_philos(global);
	return (global);
}

int	main(int argc, char **argv)
{
	int		*args;
	int		i;
	t_glob	*zala;

	args = (int *)malloc(sizeof(int) * 5);
	if (!ft_validate(argc, argv, args))
		return (0);
	zala = init_global(args, args[0]);
	chmo(zala);
	i = -1;
	while (++i < args[0])
		pthread_join(*(*(zala->philosophers + i))->thr, NULL);
	i = -1;
	while (++i < args[0])
	{
		pthread_mutex_destroy(&zala->forks[i]);
		free(zala->philosophers[i]->thr);
		free(zala->philosophers[i]);
	}
	free(zala->philosophers);
	free(zala->forks);
	free(zala);
	free(args);
	return (0);
}
