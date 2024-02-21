/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:58:44 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/21 16:21:36 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_map *map)
{
	map->map = NULL;
	map->n_tex = NULL;
	map->s_tex = NULL;
	map->e_tex = NULL;
	map->w_tex = NULL;
	map->f_tex = NULL;
	map->c_tex = NULL;
}

static void	init_player_ns(t_map *game, int i, int k)
{
	if (game->map[i][k] == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (game->map[i][k] == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
}

static void	init_player_ew(t_map *game, int i, int k)
{
	if (game->map[i][k] == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (game->map[i][k] == 'W')
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
				data->px = j;
				data->py = i;
				data->angle = (data->map[i][j] == 'N') * 90
					+ (data->map[i][j] == 'W') * 180
					+ (data->map[i][j] == 'S') * 270;
				data->map[i][j] = '0';
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	init_struct(&map);
	i = -1;
	if (argc == 2 && check_arg(argv[1]))
	{
		map.map = malloc(sizeof(char *));
		init_tab(&map, argv[1]);
		if (parsing(&map))
		{
			create_player(&map);
			exec(&map);
			printf("\n------------SUCCES------------\n\n");
		}
		clean_all(&map);
	}
	exit(0);
}
