/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:32 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 06:37:15 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	start(t_params *params)
{
	int			i;
	pthread_t	mon_thread;

	params->start_time = get_time();
	i = -1;
	while (++i < params->num_philos)
	{
		params->philos[i].time_last_meal = params->start_time;
		pthread_create(&params->philos[i].thread, \
				NULL, &main_routine, &params->philos[i]);
	}
	pthread_create(&mon_thread, NULL, &ph_monitor, params->philos);
	pthread_detach(mon_thread);
	i = -1;
	while (++i < params->num_philos)
		pthread_join(params->philos[i].thread, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	*params;

	if (check_input(argc, argv))
		return (1);
	params = init_params(argc, argv);
	init_forks(params);
	init_philos(params);
	start(params);
	ph_free(params);
	return (0);
}
