/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:14:08 by lwendi            #+#    #+#             */
/*   Updated: 2022/04/18 21:41:08 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo {
	int			ident;
	pthread_t	*thr;
	void		*glob;
	int			cur_state;
	time_t		last_meal;
	int			fork_left_pos;
	int			fork_right_pos;
	int			eat_count;
	int			status;

}	t_phil;

typedef struct s_glob{
	t_phil			**philosophers;
	pthread_mutex_t	*forks;
	int				ttd;
	int				tte;
	int				tts;
	int				status;
	int				quantity;
	int				num_to_eat;
	struct timeval	start;
	pthread_mutex_t	mut;

}	t_glob;

void			*live(void *arg);
int				check_state(t_glob *info, int eat_count);
void			act(t_glob *info, t_phil *self);
int				ft_validate(int argc, char **argv, int *target);
void			die(t_glob *info, int id);
void			eat(t_glob *info, t_phil *self);
time_t			get_ts(struct timeval *start);
void			think(t_glob *info, t_phil *self);
void			start_philos(t_glob *global);
void			kal_usleep(int wait, struct timeval *start);
t_phil			*new_philosopher(void *glob, int id);
void			chmo(t_glob *info);
void			_log(const char *message, t_glob *info, t_phil *self);
int				pokushali(t_glob *info);

#endif
