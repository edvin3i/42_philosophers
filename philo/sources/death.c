/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:18:52 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 03:46:39 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_kill(t_philo *philo)
{
	if (!philo->params->is_died)
	{	
		pthread_mutex_lock(&philo->params->ph_printf);
		philo->params->is_died = 1;
		printf("%010lld %d %s\n", get_time() - philo->params->start_time, \
				philo->id, "\e[41mis died\e[0m");
	}
	pthread_mutex_unlock(&philo->params->ph_printf);
}

void	*ph_monitor(void *philos)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)philos;
	while (!p->params->is_died)
	{
		i = -1;
		while (++i < p->params->num_philos)
		{
			if ((get_time() - p->time_last_meal) >= p->params->time_to_die)
				ph_kill(&p[i]);
		}
	}
	return (NULL);
}
