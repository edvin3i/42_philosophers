/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:47:27 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/15 15:58:52 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_params(int argc, char **argv)
{
    t_params *params;
    
    params = (t_params*) malloc(sizeof(t_params));
    if (!params)
    {
        error ("Not allocated memory for params struct.");   
        return ;
    }
    if (argc == 6)
        params->num_meals = ft_atoi(argv[5]);
    params->num_philos = ft_atoi(argv[1]);
    params->time_to_die = ft_atoi(argv[2]);
    params->time_to_eat = ft_atoi(argv[3]);
    params->time_to_sleep = ft_atoi(argv[4]);
    
}