/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:47:21 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/21 15:49:41 by tomuller         ###   ########.fr       */
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

	if (commande == 53)
		fonc_exit(map);
	nbr++;
	ft_printf("Mouvement: %i\n", nbr);
	if (commande == 13)
		up(map, 13);
	if (commande == 1)
		down(map, 1);
	if (commande == 0)
		left(map, 0);
	if (commande == 2)
		right(map, 2);
	add_image_window(map);
	if (map->nbr_item == 0)
		item_png(map);
	return (1);
}
