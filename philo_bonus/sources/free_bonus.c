/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/06 17:14:16 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ph_unlink_all(void)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_printf");
}

void	ph_close_all(t_philo *philo)
{
	sem_close(philo->sem_fork);
	sem_close(philo->sem_printf);
}

void	ph_free(t_philo *philo)
{
	ph_unlink_all();
	free(philo->pid);
	free(philo);
}

int	ph_kill(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->num_philos)
		kill(philo->pid[i], SIGKILL);
	return (0);
}
