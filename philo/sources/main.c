/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:32 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/30 14:19:55 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	start(t_params *params)
{
	int			i;
	pthread_t	mon_thread;

	init_forks(params);
	init_philos(params);
	gettimeofday(&params->start_time, NULL);
	i = -1;
	while(++i < params->num_philos)
	{
		params->philos[i].time_last_meal = params->start_time;
		pthread_create(&params->philos[i].thread, NULL, &main_routine, &params->philos[i]);
	}
	pthread_create(&mon_thread, NULL, &ph_monitor, params->philos);
	i = -1;
	while(++i < params->num_philos)
		pthread_join(params->philos[i].thread, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params *params;

	if (check_input(argc, argv))
		return (1);
	params = init_params(argc, argv);
	start(params);
	ph_free(params);
	printf("Message");
	return (0);
}
