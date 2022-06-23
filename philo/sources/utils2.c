/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:30:40 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/15 16:00:34 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
	c == '\f' || c == '\r' || c == ' ');
}

int	ft_isdigit(int c)
{
	if (c >= 0x30 && c <= 0x39)
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (ret > INT_MAX)
			return (-1);
		else if (ret < INT_MIN)
			return (0);
	}
	return ((long)ret);
}
