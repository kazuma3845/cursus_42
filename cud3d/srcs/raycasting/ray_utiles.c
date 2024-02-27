/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:02:48 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/27 13:03:32 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_map *lst, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)X_RES - 1;
	ray->pos_x = lst->px;
	ray->pos_y = lst->py;
	ray->dir_x = lst->dir_x + lst->plane_x * ray->camera_x;
	ray->dir_y = lst->dir_y + lst->plane_y * ray->camera_x;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	ray->side_x = 0;
	ray->side_y = 0;
	ray->perp_wall_dist = 0;
	ray->hit = 0;
	ray->map_x = lst->px;
	ray->map_y = lst->py;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->door = 0;
}

int	handling_hud(int a, int b, char c)
{
	if (c == 'm')
	{
		if (a < b)
			return (b);
		else
			return (a);
	}
	else if (c == 'l')
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	return (0);
}

int	calcul_y(t_ray *ray, int y)
{
	int	tex_y;
	int	d;

	d = y * 256 - Y_RES * 128 + ray->line_height * 128;
	tex_y = ((d * TEX_SIZE) / ray->line_height) / 256;
	return (tex_y);
}

int	calcul_x(t_map *lst, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = lst->py + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = lst->px + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEX_SIZE);
	if ((ray->side == 0 && ray->dir_x > 0) || (ray->side == 1
			&& ray->dir_y < 0))
		tex_x = TEX_SIZE - tex_x - 1;
	return (128 - tex_x);
}

void	put_pixel(t_map *lst, int x, int y, int color)
{
	char	*dst;

	dst = lst->addr + (y * lst->len + x * (lst->bpp / 8));
	*(unsigned int *)dst = color;
}
