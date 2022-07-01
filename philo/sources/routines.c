/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:30:40 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/02 01:09:32 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ph_fthought(t_philo *philo)
{
	ph_printf(philo, "is thinking");
	ft_usleep(philo->params->time_to_die / 2, philo);
}

void	ph_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ph_printf(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	ph_printf(philo, "has taken a fork");
	ph_printf(philo, "is eating");
	pthread_mutex_lock(&philo->mealtime);
	philo->count_meals++;
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&philo->mealtime);
	ft_usleep(philo->params->time_to_eat, philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ph_printf(philo, "is sleeping");
	ft_usleep(philo->params->time_to_sleep, philo);
	ph_printf(philo, "is thinking");
	if (philo->params->nm_flag && \
		(philo->count_meals >= philo->params->num_meals))
		return ;
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
		ph_fthought(philo);
	pthread_mutex_lock(&p->mealtime);
	while (!p->params->is_died && !(p->params->nm_flag \
			&& p->count_meals >= p->params->num_meals))
	{
		pthread_mutex_unlock(&p->mealtime);
		ph_routine(p);
	}
	pthread_mutex_unlock(&p->mealtime);
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
	return (NULL);
}
