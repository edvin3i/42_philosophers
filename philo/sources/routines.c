/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:30:40 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 04:27:15 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_routine(t_philo *philo)
{
	if (philo->params->is_died)
		return ;
	pthread_mutex_lock(philo->l_fork);
	ph_printf(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	ph_printf(philo, "has taken a fork");
	philo->count_meals++;
	philo->time_last_meal = get_time();
	ph_printf(philo, "is eating");
	ft_usleep(philo->params->time_to_eat, philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	//if (philo->params->nm_flag && (philo->count_meals >= philo->params->num_meals))
	//	return ;
	ph_printf(philo, "is sleeping");
	ft_usleep(philo->params->time_to_sleep, philo);
	ph_printf(philo, "is thinking");
}

void	*main_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->params->num_philos == 1)
	{
		pthread_mutex_lock(p->l_fork);
		ph_printf(p, "has taken a fork");
		ft_usleep(p->params->time_to_die, philo);
		return (NULL);
	}
	if (p->id % 2)
		ft_usleep(p->params->time_to_die / 2, philo);
	while (!p->params->is_died && !(p->params->nm_flag \
			&& p->count_meals >= p->params->num_meals))
		ph_routine(p);
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
	return (NULL);
}
