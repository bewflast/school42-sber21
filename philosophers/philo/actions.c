/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:14:21 by lwendi            #+#    #+#             */
/*   Updated: 2022/04/18 21:48:49 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_log(const char *message, t_glob *info, t_phil *self)
{
	if (check_state(info, self->eat_count))
	{
		pthread_mutex_lock(&info->mut);
		printf("\n[%ld] %d %s ", get_ts(&info->start), self->ident, message);
		pthread_mutex_unlock(&info->mut);
	}
}

void	eat(t_glob *info, t_phil *self)
{
	pthread_mutex_lock(&info->mut);
	self->last_meal = get_ts(&info->start);
	pthread_mutex_unlock(&info->mut);
	_log("is eating", info, self);
	kal_usleep(info->tte, &info->start);
	pthread_mutex_unlock(&info->forks[self->fork_left_pos]);
	pthread_mutex_unlock(&info->forks[self->fork_right_pos]);
	self->cur_state = 0;
	self->eat_count++;
}

void	think(t_glob *info, t_phil *self)
{
	_log("is thinking", info, self);
	pthread_mutex_lock(&info->forks[self->fork_left_pos]);
	_log("has taken a left fork", info, self);
	pthread_mutex_lock(&info->forks[self->fork_right_pos]);
	_log("has taken a right fork", info, self);
	self->cur_state = 1;
}

void	kal_usleep(int wait, struct timeval *start)
{
	time_t	time;

	time = get_ts(start) + (time_t)wait;
	while (get_ts(start) < time)
		usleep(50);
}

void	*live(void *arg)
{
	t_phil	*self;
	t_glob	*info;

	self = (t_phil *)arg;
	info = self->glob;
	while (1)
	{
		if (!check_state(info, self->eat_count))
			break ;
		if (self->cur_state == 1)
			eat(info, self);
		else if (self->cur_state == 0)
		{
			_log("is sleeping", info, self);
			self->cur_state = 2;
			kal_usleep(info->tts, &info->start);
		}
		else
			think(info, self);
	}
	pthread_mutex_lock(&info->mut);
	self->status = 1;
	pthread_mutex_unlock(&info->mut);
	return (0);
}
