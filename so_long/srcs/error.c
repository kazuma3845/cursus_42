/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:10:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/22 12:00:56 by tomuller         ###   ########.fr       */
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
	if (error_chemin(x) == 1)
		return (1);
	return (0);
}

void	find_p(t_game *map, int line, int col)
{
	if (map->map_check[line][col] == 'P')
	{
		map->c++;
		return ;
	}
	map->map_check[line][col] = '1';
	if (col + 1 < map->x_max && (map->map_check[line][col + 1] == '0'
			|| map->map_check[line][col + 1] == 'C' || map->map_check[line][col
			+ 1] == 'P'))
		find_p(map, line, col + 1);
	if (col - 1 >= 0 && (map->map_check[line][col - 1] == '0'
			|| map->map_check[line][col - 1] == 'C' || map->map_check[line][col
			- 1] == 'P'))
		find_p(map, line, col - 1);
	if (line + 1 < map->y_max && (map->map_check[line + 1][col] == '0'
			|| map->map_check[line + 1][col] == 'C' || map->map_check[line
			+ 1][col] == 'P'))
		find_p(map, line + 1, col);
	if (line - 1 >= 0 && (map->map_check[line - 1][col] == '0'
			|| map->map_check[line - 1][col] == 'C' || map->map_check[line
			- 1][col] == 'P'))
		find_p(map, line - 1, col);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	i = 0;
	a = dst;
	b = src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i != n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}

int	error_chemin(t_game *map)
{
	int		col;
	int		line;
	char	**map_backup;
	int		i;

	line = 1;
	col = 1;
	map_backup = malloc(map->y_max * sizeof(char *));
	i = 0;
	while (i < map->y_max)
	{
		map_backup[i] = malloc(map->x_max * sizeof(char));
		ft_memcpy(map_backup[i], map->map_check[i], map->x_max);
		i++;
	}
	while (line < map->y_max - 1)
	{
		col = 1;
		while (col < map->x_max)
		{
			if (map->map_check[line][col] == 'C'
				|| map->map_check[line][col] == 'E')
			{
				find_p(map, line, col);
				i = 0;
				while (i < map->y_max)
				{
					ft_memcpy(map->map_check[i], map_backup[i], map->x_max);
					i++;
				}
			}
			col++;
		}
		line++;
	}
	i = 0;
	while (i < map->y_max)
	{
		free(map_backup[i]);
		i++;
	}
	free(map_backup);
	if (map->c != map->nbr_item + 1)
		return (1);
	return (0);
}
