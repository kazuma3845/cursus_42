/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:10:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/21 15:51:54 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	error_car(t_game *x)
{
	x->y = 0;
	x->x = 0;
	x->p = 0;
	x->c = 0;
	x->e = 0;
	while (x->map[x->y] != NULL)
	{
		if (x->map[x->y][x->x] == 'P')
			x->p++;
		if (x->map[x->y][x->x] == 'C')
			x->c++;
		if (x->map[x->y][x->x] == 'E')
			x->e++;
		if (x->map[x->y][x->x] == '\0')
		{
			x->y++;
			x->x = 0;
		}
		x->x++;
	}
	if (x->p != 1 || x->e != 1 || x->c < 1)
		return (1);
	return (0);
}

int	error_wall(t_game *x)
{
	x->x = 0;
	x->y = 1;
	while (x->x != x->x_max)
	{
		if (x->map[0][x->x] != '1'|| x->map[x->y_max - 1][x->x] != '1')
			return (1);
		x->x++;
	}
	x->x = 0;
	while (x->y != x->y_max)
	{
		if (x->map[x->y][0] != '1' || x->map[x->y][x->x_max - 1] != '1')
			return (1);
		if (x->x == x->x_max)
		{
			x->y++;
			x->x = 0;
		}
		x->x++;
	}
	return (0);
}

int	error_size(t_game *x)
{
	x->x = 0;
	x->y = 0;
	if (x->x_max < 3 || x->y_max < 3)
		return (1);
	while (x->y != x->y_max)
	{
		if ((x->map[x->y][x->x] == '\n' && x->x != x->x_max) || (x->map[x->y][x->x] == '\0' && x->x != x->x_max))
			return (1);
		if (x->map[x->y][x->x] == '\0' || x->map[x->y][x->x] == '\n')
		{
			x->y++;
			x->x = 0;
		}
		x->x++;
	}
	return (0);
}

int	error_map(t_game *x)
{
	if (error_car(x) == 1 || error_wall(x) == 1 || error_size(x) == 1)
		return (1);
	// if (error_chemin(map) == 1)
	// 	return (1);
	return (0);
}
