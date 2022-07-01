/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:18:52 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 16:09:08 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ph_kill(t_philo *philo)
{
	if (!philo->params->is_died)
	{
		pthread_mutex_lock(&philo->params->ph_printf);
		philo->params->is_died = 1;
		printf("%lld %d %s\n", \
				get_time() - philo->params->start_time, \
				philo->id, "\e[41mis died\e[0m");
	}
	pthread_mutex_unlock(&philo->params->ph_printf);
	pthread_mutex_unlock(&philo->mealtime);
}

void	*ph_monitor(void *philos)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)philos;
	while (!p[0].params->is_died)
	{
		i = -1;
		while (++i < p[0].params->num_philos)
		{	
			pthread_mutex_lock(&p[i].mealtime);
			if ((get_time() - p[i].time_last_meal) >= p[i].params->time_to_die)
				ph_kill(&p[i]);
			pthread_mutex_unlock(&p[i].mealtime);
			pthread_mutex_lock(&p[i].mealtime);
			if (p->params->nm_flag && \
				(p[i].count_meals >= p->params->num_meals))
			{
				pthread_mutex_unlock(&p[i].mealtime);
				return (NULL);
			}
			pthread_mutex_unlock(&p[i].mealtime);
		}
	}
	return (NULL);
}
