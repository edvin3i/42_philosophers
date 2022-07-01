/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 06:30:36 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_free(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->num_philos)
	{
		pthread_mutex_unlock(&params->forks[i]);
		pthread_mutex_destroy(&params->forks[i]);
		pthread_mutex_unlock(&params->philos[i].mealtime);
		pthread_mutex_destroy(&params->philos[i].mealtime);
	}
	pthread_mutex_destroy(&params->ph_printf);
	if (params->philos)
		free(params->philos);
	if (params->forks)
		free(params->forks);
	if (params)
		free(params);
}
