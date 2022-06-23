/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:30:59 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/20 14:50:36 by gbreana          ###   ########.fr       */
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
# include <sys/time.h>
/*
	Structures
*/
typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_meal;
	long			time_start;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	
	
	
}	t_philo;

typedef struct s_params
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_meals;
	time_t	start_time;
	int		is_end;
	mutex	
}	t_params;
/*
	Utils
*/
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
long	ft_atoi(const char *str);
int		error(char *message);
void	ft_usleep(int time);
/*
	Functions for input check
*/
int		check_input(int argc, char **argv);
/*
	Initialisation
*/
void	init_params(int argc, char **argv);
void	init_philo(int argc, char **argv);

#endif