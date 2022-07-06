/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/06 17:06:02 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	ft_usleep(long long time, t_philo *philo)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while (((((now.tv_sec - start.tv_sec) * 1000) + \
		(now.tv_usec - start.tv_usec) / 1000) < time) \
		&& !philo->is_died)
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
	printf("\n\e[41mError: %s\e[0m", message);
	return (1);
}

void	ph_printf(t_philo *philo, char *str)
{
	sem_wait(philo->sem_printf);
	if (!philo->is_died)
		printf("%lld %d %s\n", get_time() - \
				philo->start_time, philo->id, str);
	sem_post(philo->sem_printf);
}
