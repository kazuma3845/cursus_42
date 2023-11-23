/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:27 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 16:12:04 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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

int	find_p(t_game *map, int line, int col)
{
	if (map->map[line][col] == 'P')
	{
		map->c++;
		return (1);
	}
	if (map->map[line][col] != '0' && map->map[line][col] != 'C')
		return (0);
	map->map[line][col] = '1';
	if (col + 1 < map->x_max && find_p(map, line, col + 1))
		return (1);
	if (col - 1 >= 0 && find_p(map, line, col - 1))
		return (1);
	if (line + 1 < (map->y_max - 1) && find_p(map, line + 1, col))
		return (1);
	if (line - 1 >= 0 && find_p(map, line - 1, col))
		return (1);
	return (0);
}

void	backtracking2(t_game *map, char **map_backup, int line, int col)
{
	int	i;

	i = 0;
	while (i < map->y_max)
	{
		ft_memcpy(map_backup[i], map->map[i], map->x_max);
		i++;
	}
	if (map->map[line][col] == 'E')
		map->map[line][col] = 'C';
	find_p(map, line, col);
	i = 0;
	while (i < map->y_max)
	{
		ft_memcpy(map->map[i], map_backup[i], map->x_max);
		i++;
	}
}

void	backtracking(t_game *map, char **map_backup, int line)
{
	int	col;

	while (line < map->y_max - 1)
	{
		col = 1;
		while (col < map->x_max)
		{
			if (map->map[line][col] == 'C' || map->map[line][col] == 'E')
				backtracking2(map, map_backup, line, col);
			col++;
		}
		line++;
	}
}

int	error_chemin(t_game *map)
{
	int		line;
	char	**map_backup;
	int		i;

	line = 1;
	map_backup = malloc(map->y_max * sizeof(char *));
	i = 0;
	while (i < map->y_max)
	{
		map_backup[i] = malloc(sizeof(char) * map->x_max + 1);
		i++;
	}
	backtracking(map, map_backup, line);
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
