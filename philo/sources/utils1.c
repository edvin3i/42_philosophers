/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/30 15:22:05 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
/*
void	ft_usleep(int time)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while ((((now.tv_sec - start.tv_sec) * 1000) + \
		(now.tv_usec - start.tv_usec) / 1000) < time)
	{
		usleep(10);
		gettimeofday(&now, NULL);
	}
}
*/

time_t	get_time(struct timeval start_time)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	return ((tval.tv_sec - start_time.tv_sec) * 1000000
		+ tval.tv_usec - start_time.tv_usec);
}

int	error(char *message)
{
	printf("\n\e[41mError: %s\e[0m", message);
	return (1);
}

void	ph_printf(t_philo *philo, char *str)
{
	struct timeval start_time;

	start_time = philo->params->start_time;
	pthread_mutex_lock(&philo->params->ph_printf);
	if (!philo->params->is_died)
		printf("%010ld    %d %s\n", get_time(start_time), philo->id, str);
	pthread_mutex_unlock(&philo->params->ph_printf);
}
