/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:32 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/08 06:13:50 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	start(t_philo *philo)
{
	philo->start_time = get_time();
	main_routine(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (check_input(argc, argv))
		return (1);
	philo = init_philo(argc, argv);
	ph_init_pids(philo);
	start(philo);
	ph_free(philo);
	return (0);
}
