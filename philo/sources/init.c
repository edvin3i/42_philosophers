/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:47:27 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/01 06:28:45 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_params	*init_params(int argc, char **argv)
{
	t_params	*params;

	params = (t_params *) malloc(sizeof(t_params));
	memset(params, 0, sizeof(t_params));
	if (!params)
	{
		error ("Not allocated memory for params struct.");
		return (NULL);
	}
	params->nm_flag = 0;
	if (argc == 6)
	{
		params->nm_flag = 1;
		params->num_meals = ft_atoi(argv[5]);
	}
	params->num_philos = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->start_time = 0;
	pthread_mutex_init(&params->ph_printf, NULL);
	return (params);
}

int	init_forks(t_params *params)
{
	int		i;
	t_mutex	*forks;

	i = -1;
	forks = (t_mutex *)malloc(sizeof(t_mutex) * params->num_philos);
	if (!forks)
	{
		free(params);
		error("Not allocated memory for forks (mutexes).");
		return (1);
	}	
	while (++i < params->num_philos)
		pthread_mutex_init(&forks[i], NULL);
	params->forks = forks;
	return (0);
}

int	init_philos(t_params *params)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *) malloc(sizeof(t_philo) * params->num_philos);
	if (!philos)
	{
		error ("Not allocated memory for philo struct.");
		free(params->forks);
		free(params);
		return (1);
	}
	i = -1;
	while (++i < params->num_philos)
	{
		memset(&philos[i], 0, sizeof(t_philo));
		philos[i].id = i + 1;
		philos[i].l_fork = &params->forks[i];
		philos[i].r_fork = &params->forks[i + 1 % params->num_philos];
		philos[i].params = params;
		philos[i].count_meals = 0;
		pthread_mutex_init(&philos[i].mealtime, NULL);
	}
	params->philos = philos;
	return (0);
}
