/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:58:44 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/19 15:18:14 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	i = -1;
	if (argc == 2 && check_arg(argv[1]))
	{
		map.map = malloc(sizeof(char *));
		init_tab(&map, argv[1]);
		if (parsing(&map))
		{
			printf("\n------------SUCCES------------\n\n");
		}
		clean_all(&map);
	}
	return (0);
}
