/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:13:22 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/23 11:22:06 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_nsew(t_map *game)
{
	game->texture[0]->addr = mlx_get_data_addr(game->txtrs[0]->ptr,
			&game->texture[0]->bpp, &game->texture[0]->len, &game->texture[0]->endian);
	game->texture[3]->addr = mlx_get_data_addr(game->txtrs[3]->ptr,
			&game->texture[3]->bpp, &game->texture[3]->len, &game->texture[3]->endian);
	game->texture[2]->addr = mlx_get_data_addr(game->txtrs[2]->ptr,
			&game->texture[2]->bpp, &game->texture[2]->len, &game->texture[2]->endian);
	game->texture[1]->addr = mlx_get_data_addr(game->txtrs[1]->ptr,
			&game->texture[1]->bpp, &game->texture[1]->len, &game->texture[1]->endian);
}

void init_int(t_map *lst)
{	
	lst->texture[0] = malloc(sizeof(t_texture));
	lst->texture[1] = malloc(sizeof(t_texture));
	lst->texture[2] = malloc(sizeof(t_texture));
	lst->texture[3] = malloc(sizeof(t_texture));
	lst->texture[0]->addr = NULL;
	lst->texture[0]->len = 0;
	lst->texture[0]->bpp = 0;
	lst->texture[0]->endian = 0;
	lst->texture[1]->addr = NULL;
	lst->texture[1]->len = 0;
	lst->texture[1]->bpp = 0;
	lst->texture[1]->endian = 0;
	lst->texture[2]->addr = NULL;
	lst->texture[2]->len = 0;
	lst->texture[2]->bpp = 0;
	lst->texture[2]->endian = 0;
	lst->texture[3]->addr = NULL;
	lst->texture[3]->len = 0;
	lst->texture[3]->bpp = 0;
	lst->texture[3]->endian = 0;
}

void	init_textures(t_map *lst)
{
	init_int(lst);
	set_nsew(lst);
}
