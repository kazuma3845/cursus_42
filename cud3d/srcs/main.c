/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:58:44 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/23 10:49:49 by kazuma3845       ###   ########.fr       */
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
			printf("\n------------SUCCES------------\n\n");
		}
		clean_all(&map);
	}
	exit(0);
}
