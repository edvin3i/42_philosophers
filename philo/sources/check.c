/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:07:06 by gbreana           #+#    #+#             */
/*   Updated: 2022/06/15 15:48:52 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
	{
		error("Wrong number of arguments.");
		return (-1);
	}
		
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (++j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
				{
					error("Some argument(s) is not a number.");
					return (-1);
				}
		}
	}
	return (0);
}
