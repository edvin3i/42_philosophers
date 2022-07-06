/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:47:27 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/06 18:07:41 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	philo = (t_philo *) malloc(sizeof(t_philo) * philo->num_philos);
	if (!philo)
	{
		error ("Not allocated memory for philo struct.");
		return (NULL);
	}
	philo->nm_flag = 0;
	if (argc == 6)
	{
		philo->nm_flag = 1;
		philo->num_meals = ft_atoi(argv[5]);
	}
	philo->num_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->start_time = 0;
	return (philo);
}

int	ph_init_pids(t_philo *philo)
{
	ph_unlink_all(philo);
	philo->sem_fork = sem_open("sem_fork", O_CREAT, S_IRWXU, philo->num_philos);
	philo->sem_printf = sem_open("sem_printf", O_CREAT, S_IRWXU, 1);
	if (philo->sem_fork == SEM_FAILED || philo->sem_printf == SEM_FAILED)
	{
		error("Semaphores are not created!\n");
		return (1);
	}
	philo->pid = malloc(sizeof(pid_t) * philo->num_philos);
	if (!philo->pid)
	{
		error("Pids are not created!\n");
		ph_close_all(philo);
		return (1);
	}
	return (0);
}
