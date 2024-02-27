/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:38:37 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 16:30:30 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_textures(t_text *texture, char *addr, int len, int bpp)
{
	texture->addr = addr;
	texture->len = len;
	texture->bpp = bpp;
}

void	get_texture2(t_text *text, t_map *lst, t_ray *ray)
{
	if (ray->dir_y > 0)
		set_textures(text, lst->texture[SPR_SOUTH]->addr,
			lst->texture[SPR_SOUTH]->len, lst->texture[SPR_SOUTH]->bpp);
	else
		set_textures(text, lst->texture[SPR_NORTH]->addr,
			lst->texture[SPR_NORTH]->len, lst->texture[SPR_NORTH]->bpp);
}

int	get_texture(t_map *lst, t_ray *ray, int tex_x, int tex_y)
{
	t_text	text;
	int		index;

	if (ray->door == 1)
	{
		set_textures(&text, lst->texture[SPR_DOOR]->addr,
			lst->texture[SPR_DOOR]->len, lst->texture[SPR_DOOR]->bpp);
	}
	else if (ray->side == 1)
	{
		get_texture2(&text, lst, ray);
	}
	else
	{
		if (ray->dir_x > 0)
			set_textures(&text, lst->texture[SPR_EAST]->addr,
				lst->texture[SPR_EAST]->len, lst->texture[SPR_EAST]->bpp);
		else
			set_textures(&text, lst->texture[SPR_WEST]->addr,
				lst->texture[SPR_WEST]->len, lst->texture[SPR_WEST]->bpp);
	}
	tex_x = fmax(0, fmin(tex_x, TEX_SIZE - 1));
	tex_y = fmax(0, fmin(tex_y, TEX_SIZE - 1));
	index = tex_y * text.len + tex_x * (text.bpp / 8);
	return (*(int *)(text.addr + index));
}

void	add_texture(t_map *lst, t_ray *ray, int x)
{
	int				y;
	unsigned int	color;
	int				tex_x;
	int				tex_y;
	int				end_y;

	y = handling_hud(ray->draw_start, 0, 'm');
	end_y = handling_hud(ray->draw_end, Y_RES, 'l');
	while (y < end_y)
	{
		tex_x = calcul_x(lst, ray);
		tex_y = calcul_y(ray, y);
		color = get_texture(lst, ray, tex_x, tex_y);
		put_pixel(lst, x, y, color);
		y++;
	}
}
