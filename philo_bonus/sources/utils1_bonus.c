/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/08 07:31:00 by gbreana          ###   ########.fr       */
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
		&& !philo->flag_death)
	{
		usleep(10);
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

void	error(char *message)
{
	write(2, "\e[41mError: ", 12);
	write(2, message, ft_strlen(message));
	write(2, "\e[0m", 4);
	write(2, "\n", 1);
	exit(1);
}

void	ph_printf(t_philo *philo, char *str)
{
	sem_wait(philo->sem_printf);
	if (!philo->flag_death)
		printf("%010lld %d %s\n", get_time() - \
				philo->start_time, philo->id, str);
	sem_post(philo->sem_printf);
}

void	ph_sem_post_n(sem_t *sem, int num)
{
	while (--num >= 0)
		sem_post(sem);
}
