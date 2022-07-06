/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:30:59 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/06 17:14:23 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_params	t_params;
typedef struct s_philo	t_philo;

/*
	Structures
*/
typedef struct s_params
{
	int	nothing;
}	t_params;

typedef struct s_philo
{
	int				id;
	pid_t			*pid;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				nm_flag;
	int				count_meals;
	int				flag_death;
	int				is_died;
	long long		start_time;
	long long		time_last_meal;
	sem_t			*sem_fork;
	sem_t			*sem_printf;
	pthread_t		mon_thread;
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
t_philo		*init_philo(int argc, char **argv);
int			ph_init_pids(t_philo *philo);
int			start(t_philo *philo);
/*
	Routines
*/
int			main_routine(t_philo *philo);
void		*ph_monitor(void *philo);
int			ph_routine(t_philo *philo);
/*
	Free and destroy
*/
int			ph_kill(t_philo *philo);
void		ph_unlink_all(void);
void		ph_close_all(t_philo *philo);
void		ph_free(t_philo *philo);

#endif