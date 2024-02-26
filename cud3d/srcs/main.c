/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:58:44 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/26 13:15:21 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// animation
// porte

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

int	main(int argc, char **argv)
{
	t_map	map;

	init_struct(&map);
	if (argc == 2 && check_arg(argv[1]))
	{
		map.map = malloc(sizeof(char *));
		init_tab(&map, argv[1]);
		if (parsing(&map))
		{
			create_player(&map);
			exec(&map);
		}
		clean_all(&map);
	}
	exit(0);
}
