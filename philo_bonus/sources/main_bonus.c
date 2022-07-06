/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:34:32 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/06 18:04:42 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	ph_wait(t_philo *philo)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WEXITSTATUS(status))
		{
			ph_kill(philo);
			return (0);
		}	
	}
	return (1);
}

int	start(t_philo *philo)
{
	int	i;
	int	tmp;

	philo->start_time = get_time();
	i = -1;
	while (++i < philo->num_philos)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
		{
			error("Process does not created!\n");
			return (1);
		}
		else if (philo->pid[i] == 0)
		{
			philo->id = i + 1;
			philo->time_last_meal = philo->start_time;
			if (main_routine(philo))
				return (1);
		}
		ph_wait(philo);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (check_input(argc, argv))
		return (1);
	philo = init_philo(argc, argv);
	start(philo);
	ph_free(philo);
	return (0);
}
