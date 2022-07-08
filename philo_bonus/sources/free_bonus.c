/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/08 06:36:35 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ph_unlink_all(void)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_printf");
	sem_unlink("sem_start");
	sem_unlink("sem_kill");
}

void	ph_close_all(t_philo *philo)
{
	sem_close(philo->sem_fork);
	sem_close(philo->sem_printf);
	sem_close(philo->sem_start);
	sem_close(philo->sem_kill);
}

void	ph_free(t_philo *philo)
{
	ph_unlink_all();
	if (philo->pids >= 0)
		free(philo->pids);
	free(philo);
}

int	ph_kill(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num_philos)
		kill(philo->pids[i], SIGINT);
	return (0);
}

void	ph_killall(t_philo *philo, int num)
{
	while (--num >= 0)
		kill(philo->pids[num], SIGINT);
	free(philo->pids);
}
