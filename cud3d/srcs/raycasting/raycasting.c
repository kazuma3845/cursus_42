/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:53:52 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 16:23:28 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step(t_map *lst, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (lst->px - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - lst->px) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (lst->py - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - lst->py) * ray->delta_y;
	}
}

void	dda(t_map *lst, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (lst->map[ray->map_y][ray->map_x] == 'P')
		{
			ray->door = 1;
			ray->hit = 1;
		}
		else if (lst->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calcul_height(t_ray *ray)
{
	ray->line_height = (int)(Y_RES / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + Y_RES / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + Y_RES / 2;
	if (ray->draw_end >= Y_RES)
		ray->draw_end = Y_RES - 1;
}

void	raycasting(t_map *lst)
{
	int		x;
	t_ray	ray;

	x = -1;
	while (++x < X_RES)
	{
		init_ray(lst, &ray, x);
		step(lst, &ray);
		dda(lst, &ray);
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.side_x - ray.delta_x);
		else
			ray.perp_wall_dist = (ray.side_y - ray.delta_y);
		calcul_height(&ray);
		add_texture(lst, &ray, x);
	}
}
