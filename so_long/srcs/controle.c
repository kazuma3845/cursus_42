/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:47:21 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/21 15:02:25 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	item_png(t_game *map)
{
	int	i;
	int	j;

	if (map->map[map->y][map->x + 1] == 'E')
		map->map[map->y][map->x + 1] = 'I';
	if (map->map[map->y][map->x - 1] == 'E')
		map->map[map->y][map->x - 1] = 'I';
	if (map->map[map->y + 1][map->x] == 'E')
		map->map[map->y + 1][map->x] = 'I';
	if (map->map[map->y - 1][map->x] == 'E')
		map->map[map->y - 1][map->x] = 'I';
	map->exit = mlx_xpm_file_to_image(map->mlxpointer, "texture/o_exit.xpm", &i,
			&j);
}

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

void	fonc_exit(t_game *map)
{
	int	line;

	line = 0;
	if (map->winpointer)
		mlx_destroy_window(map->mlxpointer, map->winpointer);
	free(map->mlxpointer);
	while (line < map->y_max - 1)
		free(map->map[line++]);
	free(map->map);
	exit(0);
}

int	controle(int commande, t_game *map)
{
	static int	nbr;

	nbr++;
	printf("Mouvement: %i\n", nbr);
	if (commande == 53)
		fonc_exit(map);
	else if (commande == 13)
		up(map, 13);
	else if (commande == 1)
		down(map, 1);
	else if (commande == 0)
		left(map, 0);
	else if (commande == 2)
		right(map, 2);
	add_image_window(map);
	if (map->nbr_item == 0)
		item_png(map);
	return (1);
}