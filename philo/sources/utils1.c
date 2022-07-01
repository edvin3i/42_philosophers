/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/02 00:52:58 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_usleep(long long time, t_philo *philo)
{
	struct timeval	start;
	struct timeval	now;

	(void)philo;
	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while ((((now.tv_sec - start.tv_sec) * 1000) + \
		(now.tv_usec - start.tv_usec) / 1000) < time)
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
}

long long	get_time(void)
{
	struct timeval	tm;
	long long		now;

	gettimeofday (&tm, NULL);
	now = ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
	return (now);
}

int	error(char *message)
{
	write(2, "\e[41mError: ", 12);
	write(2, message, ft_strlen(message));
	write(2, "\e[0m", 4);
	write(2, "\n", 1);
	return (1);
}

void	ph_printf(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->params->ph_printf);
	if (!philo->params->is_died)
		printf("%010lld %d %s\n", get_time() - \
				philo->params->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->params->ph_printf);
}
