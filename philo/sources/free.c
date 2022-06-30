/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 03:48:00 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_free(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->num_philos)
		pthread_mutex_destroy(&params->forks[i]);
	pthread_mutex_destroy(&params->ph_printf);
	free(params->philos);
	free(params->forks);
	free(params);
}
