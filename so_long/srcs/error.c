/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:10:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/21 18:25:42 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	error_car(t_game *x)
{
	x->y = 0;
	x->x = 0;
	x->p = 0;
	x->nbr_item = 0;
	x->e = 0;
	while (x->map[x->y] != NULL)
	{
		if (x->map[x->y][x->x] == 'P')
			x->p++;
		if (x->map[x->y][x->x] == 'C')
			x->nbr_item++;
		if (x->map[x->y][x->x] == 'E')
			x->e++;
		if (x->map[x->y][x->x] == '\0')
		{
			x->y++;
			x->x = 0;
		}
		x->x++;
	}
	if (x->p != 1 || x->e != 1 || x->nbr_item < 1)
		return (1);
	return (0);
}

int	error_wall(t_game *x)
{
	x->x = 0;
	x->y = 1;
	while (x->x != x->x_max)
	{
		if (x->map[0][x->x] != '1' || x->map[x->y_max - 1][x->x] != '1')
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
		if ((x->map[x->y][x->x] == '\n' && x->x != x->x_max)
			|| (x->map[x->y][x->x] == '\0' && x->x != x->x_max))
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
	// if (error_chemin(x) == 1)
	// 	return (1);
	return (0);
}

void find_e(t_game *map, int line, int col)
{
	if (map->map_check[line][col + 1] == 'E')
		map->map_check[line][col + 1] = '1';
	if (map->map_check[line][col - 1] == 'E')
		map->map_check[line][col - 1] = '1';
	if (map->map_check[line + 1][col] == 'E')
		map->map_check[line + 1][col] = '1';
	if (map->map_check[line - 1][col] == 'E')
		map->map_check[line - 1][col] = '1';
}

int	error_chemin(t_game *map)
{
	int	col;
	int	line;

	line = 1;
	col = 1;
	map->y_p = 1;
	map->x_p = 1;
	while (map->map[map->y_p][map->x_p] != 'P')
	{
		if (map->x_p == map->x_max)
		{
			map->y_p++;
			map->x_p = 1;
		}
		map->x_p++;
	}
	line = 1;
	while (line < map->y_max - 1)
	{
		col = 1;
		while (col < map->x_max - 1)
		{
			if (map->map_check[line][col] == 'C' || map->map_check[line][col] == 'E')
			{
				map->y = line;
				map->x = col;
				while (map->map_check[line][col] != 'P')
				{
					find_e(map, line, col);
					if (map->map_check[line][col + 1] == '0'
						|| map->map_check[line][col + 1] == 'C'|| map->map_check[line][col + 1] == 'P')
					{
						col++;
						if (map->map_check[line + 1][col] == '1'
							&& map->map_check[line][col + 1] == '1'
							&& map->map_check[line - 1][col] == '1')
						{
							map->map_check[line][col] = '1';
							col--;
						}
					}
					else if (map->map_check[line + 1][col] == '0'
						|| map->map_check[line + 1][col] == 'C'|| map->map_check[line + 1][col] == 'P')
					{
						line++;
						if (map->map_check[line][col - 1] == '1'
							&& map->map_check[line + 1][col] == '1'
							&& map->map_check[line][col + 1] == '1')
						{
							map->map_check[line][col] = '1';
							line--;
						}
					}
					else if (map->map_check[line][col - 1] == '0'
						|| map->map_check[line][col - 1] == 'C'|| map->map_check[line][col - 1] == 'P')
					{
						col--;
						if (map->map_check[line - 1][col] == '1'
							&& map->map_check[line][col - 1] == '1'
							&& map->map_check[line + 1][col] == '1')
						{
							map->map_check[line][col] = '1';
							col++;
						}
					}
					else if (map->map_check[line - 1][col] == '0'
						|| map->map_check[line - 1][col] == 'C'|| map->map_check[line - 1][col] == 'P')
					{
						line--;
						if (map->map_check[line - 1][col] == '1'
							&& map->map_check[line][col - 1] == '1'
							&& map->map_check[line][col + 1] == '1')
						{
							map->map_check[line][col] = '1';
							line++;
						}
					}
					if (map->map_check[line - 1][col] == '1'
						&& map->map_check[line][col - 1] == '1'
						&& map->map_check[line][col + 1] == '1'
						&& map->map_check[line + 1][col] == '1')
						return (1);
				}
				map->c++;
				col = map->x + 1;
				line = map->y;
				map->map_check = map->map;
			}
			col++;
		}
		line++;
	}
	return (0);
}
