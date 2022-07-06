/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:30:40 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/06 18:05:03 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ph_routine(t_philo *philo)
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
	if (philo->nm_flag && \
		(philo->count_meals >= philo->num_meals))
		return (0);
	ph_printf(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep, philo);
	ph_printf(philo, "is thinking");
	return (0);
}

int	main_routine(t_philo *philo)
{
	t_philo	*p;

	p = philo;
	pthread_create(&philo->mon_thread, NULL, &ph_monitor, philo);
	if (p->id % 2)
		ft_usleep(p->time_to_die / 2, NULL);
	while (1)
	{
		if (p->nm_flag && (p->count_meals >= p->num_meals))
			break ;
		if (ph_routine(philo))
			break ;
	}
	pthread_join(p->mon_thread, NULL);
	return (0);
}
