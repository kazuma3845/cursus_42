/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:10:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/20 17:02:41 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	error_car(t_game *x)
{
	x->ligne = 0;
	x->col = 0;
	x->p = 0;
	x->c = 0;
	x->e = 0;
	while (x->map[x->ligne] != NULL)
	{
		if (x->map[x->ligne][x->col] == 'P')
			x->p++;
		if (x->map[x->ligne][x->col] == 'C')
			x->c++;
		if (x->map[x->ligne][x->col] == 'E')
			x->e++;
		if (x->map[x->ligne][x->col] == '\0')
		{
			x->ligne++;
			x->col = 0;
		}
		x->col++;
	}
	if (x->p != 1 || x->e != 1 || x->c < 1)
		return (1);
	return (0);
}

int	error_map(t_game *x)
{
	if (error_car(x) == 1 ||/* error_wall(&x) == 1 ||*/ error_size(x) == 1)
		return (1);
	// if (error_chemin(map) == 1)
	// 	return (1);
	return (0);
}

int	error_line(t_game *x)
{
	x->col = 0;
	x->ligne = 1;
	while (x->map[x->ligne][x->col] != '\0')
	{
		if (x->map[x->ligne][0] != '1'
			|| x->map[x->ligne][ft_strlen(x->map[x->ligne]) - 2] != '1')
			return (1);
		if (x->map[x->ligne][x->col] == '\n')
		{
			x->ligne++;
			x->col = 0;
		}
		x->col++;
	}
	x->col = 0;
	while (x->map[x->ligne][x->col] != '\0')
	{
		if (x->map[x->ligne][x->col] != '1')
			return (1);
		x->col++;
	}
	return (0);
}

int	error_wall(t_game *x)
{
	x->col = 0;
	while (x->map[0][x->col] != '\n')
	{
		if (x->map[0][x->col] != '1')
			return (1);
		x->col++;
	}
	if (error_line(x) == 1)
		return (1);
	return (0);
}

int	error_size(t_game *x)
{
	x->col = 0;
	x->ligne = 0;
	if (ft_strlen(x->map[0]) < 5)
		return (1);
	while (x->map[x->ligne] != NULL)
	{
		if ((x->map[x->ligne][x->col] == '\n'
				&& x->col != (ft_strlen(x->map[0]) - 1))
			|| (x->map[x->ligne][x->col] == '\0'
				&& x->col != (ft_strlen(x->map[0]) - 1)))
			return (1);
		if (x->map[x->ligne][x->col] == '\0'
			|| x->map[x->ligne][x->col] == '\n')
		{
			x->ligne++;
			x->col = 0;
		}
		x->col++;
	}
	if (x->ligne < 3)
		return (1);
	return (0);
}
