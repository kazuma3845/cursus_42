/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:32:06 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/27 08:37:42 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_ns(t_map *game, int i, int j)
{
	if (game->map[i][j] == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (game->map[i][j] == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
}

static void	init_player_ew(t_map *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (game->map[i][j] == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

void	create_player(t_map *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if ((data->map[i][j] == 'N') || (data->map[i][j] == 'E')
				|| (data->map[i][j] == 'S') || (data->map[i][j] == 'W'))
			{
				init_player_ns(data, i, j);
				init_player_ew(data, i, j);
				data->px = j + 0.5;
				data->py = i + 0.5;
				data->angle = (data->map[i][j] == 'N') * 270
					+ (data->map[i][j] == 'W') * 180
					+ (data->map[i][j] == 'S') * 90;
				data->map[i][j] = '0';
			}
		}
	}
}
