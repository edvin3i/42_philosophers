/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:47:27 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/08 07:28:45 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*philo;

	philo = NULL;
	philo = (t_philo *) malloc(sizeof(t_philo));
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
	philo->id = 0;
	philo->start_time = get_time();
	philo->count_meals = 0;
	philo->flag_death = 0;
	philo->flag_stop = 0;
	return (philo);
}

int	ph_init_pids(t_philo *philo)
{
	ph_unlink_all();
	philo->sem_start = sem_open("sem_start", O_CREAT, S_IRWXU, 0);
	philo->sem_fork = sem_open("sem_fork", O_CREAT, S_IRWXU, philo->num_philos);
	philo->sem_printf = sem_open("sem_printf", O_CREAT, S_IRWXU, 1);
	philo->sem_kill = sem_open("sem_kill", O_CREAT, S_IRWXU, 0);
	if (philo->sem_fork == SEM_FAILED || philo->sem_printf == SEM_FAILED \
			|| philo->sem_start == SEM_FAILED || philo->sem_kill == SEM_FAILED)
	{
		error("Semaphores are not created!\n");
		ph_unlink_all();
	}
	philo->pids = (pid_t *) malloc(sizeof(pid_t) * philo->num_philos);
	if (!philo->pids)
	{
		ph_close_all(philo);
		error("Pids are not created!\n");
	}
	return (0);
}
