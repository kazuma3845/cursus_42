/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:13:22 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 13:29:14 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_nsew(t_map *game)
{
	game->texture[SPR_NORTH]->addr = mlx_get_data_addr(game->txtrs[SPR_NORTH]->ptr,
			&game->texture[SPR_NORTH]->bpp, &game->texture[SPR_NORTH]->len,
			&game->texture[SPR_NORTH]->endian);
	game->texture[SPR_WEST]->addr = mlx_get_data_addr(game->txtrs[SPR_WEST]->ptr,
			&game->texture[SPR_WEST]->bpp, &game->texture[SPR_WEST]->len,
			&game->texture[SPR_WEST]->endian);
	game->texture[SPR_EAST]->addr = mlx_get_data_addr(game->txtrs[SPR_EAST]->ptr,
			&game->texture[SPR_EAST]->bpp, &game->texture[SPR_EAST]->len,
			&game->texture[SPR_EAST]->endian);
	game->texture[SPR_SOUTH]->addr = mlx_get_data_addr(game->txtrs[SPR_SOUTH]->ptr,
			&game->texture[SPR_SOUTH]->bpp, &game->texture[SPR_SOUTH]->len,
			&game->texture[SPR_SOUTH]->endian);
	game->texture[SPR_DOOR]->addr = mlx_get_data_addr(game->txtrs[SPR_DOOR]->ptr,
			&game->texture[SPR_DOOR]->bpp, &game->texture[SPR_DOOR]->len,
			&game->texture[SPR_DOOR]->endian);
}

void	init_int(t_map *lst)
{	
	lst->texture[SPR_NORTH] = malloc(sizeof(t_texture));
	lst->texture[SPR_SOUTH] = malloc(sizeof(t_texture));
	lst->texture[SPR_EAST] = malloc(sizeof(t_texture));
	lst->texture[SPR_WEST] = malloc(sizeof(t_texture));
	lst->texture[SPR_DOOR] = malloc(sizeof(t_texture));
	lst->texture[SPR_NORTH]->addr = NULL;
	lst->texture[SPR_NORTH]->len = 0;
	lst->texture[SPR_NORTH]->bpp = 0;
	lst->texture[SPR_NORTH]->endian = 0;
	lst->texture[SPR_SOUTH]->addr = NULL;
	lst->texture[SPR_SOUTH]->len = 0;
	lst->texture[SPR_SOUTH]->bpp = 0;
	lst->texture[SPR_SOUTH]->endian = 0;
	lst->texture[SPR_EAST]->addr = NULL;
	lst->texture[SPR_EAST]->len = 0;
	lst->texture[SPR_EAST]->bpp = 0;
	lst->texture[SPR_EAST]->endian = 0;
	lst->texture[SPR_WEST]->addr = NULL;
	lst->texture[SPR_WEST]->len = 0;
	lst->texture[SPR_WEST]->bpp = 0;
	lst->texture[SPR_WEST]->endian = 0;
	lst->texture[SPR_DOOR]->addr = NULL;
	lst->texture[SPR_DOOR]->len = 0;
	lst->texture[SPR_DOOR]->bpp = 0;
	lst->texture[SPR_DOOR]->endian = 0;
}

void	init_textures(t_map *lst)
{
	init_int(lst);
	set_nsew(lst);
}
