/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:13:22 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 16:21:22 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_nsew(t_map *g)
{
	g->texture[SPR_NORTH]->addr = mlx_get_data_addr(g->txtrs[SPR_NORTH]->ptr,
			&g->texture[SPR_NORTH]->bpp, &g->texture[SPR_NORTH]->len,
			&g->texture[SPR_NORTH]->endian);
	g->texture[SPR_WEST]->addr = mlx_get_data_addr(g->txtrs[SPR_WEST]->ptr,
			&g->texture[SPR_WEST]->bpp, &g->texture[SPR_WEST]->len,
			&g->texture[SPR_WEST]->endian);
	g->texture[SPR_EAST]->addr = mlx_get_data_addr(g->txtrs[SPR_EAST]->ptr,
			&g->texture[SPR_EAST]->bpp, &g->texture[SPR_EAST]->len,
			&g->texture[SPR_EAST]->endian);
	g->texture[SPR_SOUTH]->addr = mlx_get_data_addr(g->txtrs[SPR_SOUTH]->ptr,
			&g->texture[SPR_SOUTH]->bpp, &g->texture[SPR_SOUTH]->len,
			&g->texture[SPR_SOUTH]->endian);
	g->texture[SPR_DOOR]->addr = mlx_get_data_addr(g->txtrs[SPR_DOOR]->ptr,
			&g->texture[SPR_DOOR]->bpp, &g->texture[SPR_DOOR]->len,
			&g->texture[SPR_DOOR]->endian);
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
