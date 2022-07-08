/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:18:52 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/08 07:30:20 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

pid_t	ph_wdog(t_philo *philo)
{
	int		i;
	pid_t	wdog_pid;

	i = -1;
	wdog_pid = fork();
	if (wdog_pid == -1)
		error("watch dog does not forked.");
	else if (wdog_pid == 0)
	{
		sem_wait(philo->sem_kill);
		while (++i < philo->num_philos)
			kill(philo->pids[i], SIGINT);
		exit(0);
	}
	return (wdog_pid);
}

void	*ph_monitor(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if ((get_time() - p->time_last_meal) >= p->time_to_die)
		{	
			if (!p->flag_stop)
			{
				p->flag_death = 1;
				sem_wait(p->sem_printf);
				printf("%010lld %d %s\n", \
					get_time() - p->start_time, \
						p->id, "\e[41mdied\e[0m");
				sem_post(p->sem_kill);
				exit(0);
			}
		}
	}
	return (NULL);
}
