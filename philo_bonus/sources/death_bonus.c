/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:18:52 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/06 18:05:53 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*ph_monitor(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{	
		if ((get_time() - p->time_last_meal) >= p->time_to_die)
		{
			sem_wait(p->sem_printf);
			if (p->flag_death)
			{
				printf("%lld %d %s\n", \
					get_time() - p->start_time, \
					p->id, "\e[41mis died\e[0m");
			}
			exit(1);
		}
		else if (p->nm_flag && (p->count_meals >= p->num_meals))
			exit (0);
	}
	return (NULL);
}
