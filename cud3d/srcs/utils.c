/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:37:35 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/22 13:43:14 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	torad(double ang)
{
	return (ang * M_PI / 180);
}

int	sign(int a)
{
	if (a < 0)
		return (-1);
	else if (a > 0)
		return (1);
	else
		return (0);
}

int	get_color(char *col)
{
	char	**split;
	int		res;

	split = ft_split(col, ',');
	res = ft_atoi(split[0]);
	res = res << 8;
	res += ft_atoi(split[1]);
	res = res << 8;
	res += ft_atoi(split[2]);
	free_tab(split);
	return (res);
}
