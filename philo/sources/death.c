/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:18:52 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/30 14:33:03 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_kill(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->ph_printf);
	if (!philo->params->is_died)
		printf("%010ld    %d %s\n", get_time(philo->params->start_time), philo->id, "is died");
	philo->params->is_died = 1;
	pthread_mutex_unlock(&philo->params->ph_printf);
}

void	*ph_monitor(void *philos)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)philos;
	while(!p->params->is_died)
	{
		i = -1;
		while (++i < p->params->num_philos)
		{
			if(get_time(p->time_last_meal) >= p->params->time_to_die)
				ph_kill(&p[i]);
		}
	}
	return (NULL);
}