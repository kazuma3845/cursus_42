/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:14:53 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/15 17:19:21 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char *c)
{
	while (*c)
	{
		if (!(*c >= '0' && *c <= '9'))
			return (0);
		c++;
	}
	return (1);
}

int	check_char(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isdigit(argv[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of argument\n");
		return (0);
	}
	if (check_char(argc, argv) == 0)
	{
		printf("Wrong type of argument\n");
		return (0);
	}
	return (1);
}
