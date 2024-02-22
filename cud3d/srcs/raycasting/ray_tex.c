/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:38:37 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/22 16:42:00 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void put_pixel(t_map *lst, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = lst->mlx->addr + (y * lst->mlx->len + x * (lst->mlx->bpp / 8));
// 	*(unsigned int *)dst = color;
// }

// static void	set_textures(t_text *texture, char *addr, int len, int bpp)
// {
// 	texture->addr = addr;
// 	texture->len = len;
// 	texture->bpp = bpp;
// }

// int get_texture(t_map *lst, t_ray *ray, int tex_x, int tex_y)
// {
// 	t_text	text;
// 	int			index;

// 	if (ray->side == 1)
// 	{
// 		if (ray->dir_y > 0)
// 			set_textures(&text, lst->texture->s_addr, lst->texture->s_len,
// 				lst->texture->s_bpp);
// 		else
// 			set_textures(&text, lst->texture->n_addr, lst->texture->n_len,
// 				lst->texture->n_bpp);
// 	}
// 	else
// 	{
// 		if (ray->dir_x > 0)
// 			set_textures(&text, lst->texture->e_addr, lst->texture->e_len,
// 				lst->texture->e_bpp);
// 		else
// 			set_textures(&text, lst->texture->w_addr, lst->texture->w_len,
// 				lst->texture->w_bpp);
// 	}
// 	tex_x = fmax(0, fmin(tex_x, TEX_SIZE - 1));
// 	tex_y = fmax(0, fmin(tex_y, TEX_SIZE - 1));
// 	index = tex_y * text.len + tex_x * (text.bpp / 8);
	
// 	return (*(int *)(text.addr + index));
// }

// int calcul_x(t_map *lst, t_ray *ray)
// {
// 	double	wall_x;
// 	int		tex_x;

// 	if (ray->side == 0)
// 		wall_x = lst->py + ray->perp_wall_dist * ray->dir_y;
// 	else
// 		wall_x = lst->px + ray->perp_wall_dist * ray->dir_x;
// 	wall_x -= floor(wall_x);
// 	tex_x = (int)(wall_x * (double)TEX_SIZE);
// 	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
// 			&& ray->dir_y < 0))
// 		tex_x = TEX_SIZE - tex_x - 1;
// 	return (tex_x);
// }

// int calcul_y(t_ray *ray, int y)
// {
// 	int	tex_y;
// 	int	d;

// 	d = y * 256 - Y_RES * 128 + ray->line_height * 128;
// 	tex_y = ((d * TEX_SIZE) / ray->line_height) / 256;
// 	return (tex_y);
// }

// void	add_texture(t_map *lst, t_ray *ray, int x)
// {
// 	int				y;
// 	unsigned int	color;
// 	int				tex_x;
// 	int				tex_y;
// 	int				end_y;

// 	y = handling_hud(ray->draw_start, 30, 'm');
// 	end_y = handling_hud(ray->draw_end, Y_RES - 30, 'l');
// 	while (y < end_y)
// 	{
// 		tex_x = calcul_x(lst, ray);
// 		tex_y = calcul_y(ray, y);
// 		color = get_texture(lst, ray, tex_x, tex_y);
// 		put_pixel(lst, x, y, color);
// 		y++;
// 	}
// }
