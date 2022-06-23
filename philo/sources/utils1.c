/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 00:19:38 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/15 15:50:37 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

int	error(char *message)
{
	printf("\n\e[41mError: %s\e[0m", message);
	return (-1);
}
