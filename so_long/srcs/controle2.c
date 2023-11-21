/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:03:34 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/21 15:05:59 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	down(t_game *map, int commande)
{
	int	i;
	int	j;

	if (commande == 1)
	{
		map->player = mlx_xpm_file_to_image(map->mlxpointer,
				"texture/front.xpm", &i, &j);
		if (map->map[map->y + 1][map->x] == '1' || map->map[map->y
			+ 1][map->x] == 'E')
			return (0);
		if (map->map[map->y + 1][map->x] == 'I')
			fonc_exit(map);
		map->map[map->y++][map->x] = '0';
		map->map[map->y][map->x] = 'P';
	}
	return (1);
}

int	up(t_game *map, int commande)
{
	int	i;
	int	j;

	if (commande == 13)
	{
		map->player = mlx_xpm_file_to_image(map->mlxpointer, "texture/back.xpm",
				&i, &j);
		if (map->map[map->y - 1][map->x] == '1' || map->map[map->y
			- 1][map->x] == 'E')
			return (0);
		if (map->map[map->y - 1][map->x] == 'I')
			fonc_exit(map);
		map->map[map->y--][map->x] = '0';
		map->map[map->y][map->x] = 'P';
	}
	return (1);
}

int	right(t_game *map, int commande)
{
	int	i;
	int	j;

	if (commande == 2)
	{
		map->player = mlx_xpm_file_to_image(map->mlxpointer,
				"texture/right.xpm", &i, &j);
		if (map->map[map->y][map->x + 1] == '1' || map->map[map->y][map->x
			+ 1] == 'E')
			return (0);
		if (map->map[map->y][map->x + 1] == 'I')
			fonc_exit(map);
		map->map[map->y][map->x++] = '0';
		map->map[map->y][map->x] = 'P';
	}
	return (1);
}

int	left(t_game *map, int commande)
{
	int	i;
	int	j;

	if (commande == 0)
	{
		map->player = mlx_xpm_file_to_image(map->mlxpointer, "texture/left.xpm",
				&i, &j);
		if (map->map[map->y][map->x - 1] == '1' || map->map[map->y][map->x
			- 1] == 'E')
			return (0);
		if (map->map[map->y][map->x - 1] == 'I')
			fonc_exit(map);
		map->map[map->y][map->x--] = '0';
		map->map[map->y][map->x] = 'P';
	}
	return (1);
}