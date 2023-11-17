/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:25:48 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 16:40:09 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	start_game(t_game info)
{
	info.mlxpointer = mlx_init();
	info.winpointer = mlx_new_window(info.mlxpointer, info.x * 40, info.y * 40,
			"so_long");
	image(info);
	add_image_window(info);
}

void	add_image_window(t_game info)
{
}

void	image(t_game info)
{
	int	i;
	int	j;

	info.exit = mlx_xpm_file_to_image(info.mlxpointer, "texture/exit.xpm", &i,
			&j);
	info.item = mlx_xpm_file_to_image(info.mlxpointer, "texture/item.xpm", &i,
			&j);
	info.player = mlx_xpm_file_to_image(info.mlxpointer, "texture/player.xpm",
			&i, &j);
	info.wall = mlx_xpm_file_to_image(info.mlxpointer, "texture/wall.xpm", &i,
			&j);
	info.floor = mlx_xpm_file_to_image(info.mlxpointer, "texture/floor.xpm", &i,
			&j);
}

// esc	27 = close;
// w	87 = up;
// a	65 = left;
// s	83 = down;
// d	68 = right;