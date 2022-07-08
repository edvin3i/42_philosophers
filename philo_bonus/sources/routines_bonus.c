/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:30:40 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/08 09:40:17 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	ph_fthought(t_philo *philo)
{
	ph_printf(philo, "is thinking");
	ft_usleep(philo->time_to_die / 2, philo);
}

static void	ph_mon_start(t_philo *philo)
{
	pthread_create(&philo->mon_thread, NULL, &ph_monitor, philo);
	pthread_detach(philo->mon_thread);
}

void	ph_wait_pids(pid_t	*pids, int num)
{
	int	status;

	while (--num >= 0)
		waitpid(pids[num], &status, 0);
}

void	ph_routine(t_philo *philo)
{
	philo->time_last_meal = philo->start_time;
	ph_mon_start(philo);
	sem_wait(philo->sem_start);
	if ((!philo->count_meals) && philo->id % 2 == 0)
		ph_fthought(philo);
	while (!philo->flag_stop)
	{
		sem_wait(philo->sem_fork);
		ph_printf(philo, "has taken a fork");
		sem_wait(philo->sem_fork);
		ph_printf(philo, "has taken a fork");
		philo->count_meals++;
		philo->time_last_meal = get_time();
		ph_printf(philo, "is eating");
		ft_usleep(philo->time_to_eat, philo);
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
		ph_printf(philo, "is sleeping");
		ft_usleep(philo->time_to_sleep, philo);
		ph_printf(philo, "is thinking");
		if (philo->nm_flag && \
			(philo->count_meals >= philo->num_meals))
			philo->flag_stop = 1;
	}
	exit (0);
}

int	main_routine(t_philo *p)
{
	int		i;
	pid_t	wdog_pid;

	i = -1;
	ph_sem_post_n(p->sem_start, p->num_philos);
	while (++i < p->num_philos)
	{
		p->id = i + 1;
		p->pids[i] = fork();
		if (p->pids[i] == -1)
		{
			ph_killall(p, i);
			return (1);
		}
		else if (p->pids[i] == 0)
			ph_routine(p);
	}
	wdog_pid = ph_wdog(p);
	ph_wait_pids(p->pids, p->num_philos);
	kill(wdog_pid, SIGKILL);
	ph_close_all(p);
	return (0);
}
