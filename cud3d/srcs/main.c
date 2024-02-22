/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:58:44 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/22 13:25:40 by tomuller         ###   ########.fr       */
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
