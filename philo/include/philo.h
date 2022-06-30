/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:30:59 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 03:50:29 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <time.h>
# include <string.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_params	t_params;
typedef struct s_philo	t_philo;

/*
	Structures
*/
typedef struct s_params
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				nm_flag;
	int				is_died;
	long long		start_time;
	t_mutex			*forks;
	t_mutex			ph_printf;
	t_philo			*philos;
}	t_params;

typedef struct s_philo
{
	int				id;
	int				count_meals;
	int				flag_death;
	long long		time_last_meal;
	t_mutex			*l_fork;
	t_mutex			*r_fork;
	pthread_t		thread;
	t_params		*params;
}	t_philo;
/*
	Utils
*/
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_strlen(const char *str);
long		ft_atoi(const char *str);
int			error(char *message);
void		ft_usleep(long long time, t_philo *philo);
void		ph_printf(t_philo *philo, char *str);
long long	get_time(void);
/*
	Functions for input check
*/
int			check_input(int argc, char **argv);
/*
	Initialisation
*/
t_params	*init_params(int argc, char **argv);
int			init_forks(t_params *params);
int			init_philos(t_params *params);
int			start(t_params *params);
/*
	Routines
*/
void		*main_routine(void *philo);
void		*ph_monitor(void *philo);
void		ph_routine(t_philo *philo);
/*
	Free and destroy
*/
void		ph_kill(t_philo *philo);
void		ph_free(t_params *params);

#endif