/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:07:06 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/02 00:58:17 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_args_num(int argc)
{
	if (argc < 5 || argc > 6)
	{
		error("Wrong number of arguments.");
		return (1);
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (check_args_num(argc))
		return (1);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (++j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				error("Some argument(s) is not a number.");
				return (1);
			}
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			error("Some argument is equal or less than zero.");
			return (1);
		}
	}
	return (0);
}
