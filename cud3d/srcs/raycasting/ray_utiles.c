/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:02:48 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 13:04:07 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_ray(t_map *lst, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)X_RES -1;
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
