/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:07:00 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/27 13:24:16 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_door(t_map *lst)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = lst->px - 0.5;
	y = lst->py - 0.5;
	i = -1;
	while (lst->map[++i])
	{
		j = -1;
		while (lst->map[i][++j])
		{
			if ((lst->map[i][j] == 'P') || (lst->map[i][j] == 'p'))
			{
				if ((x < j + DOOR_DIST && x > j - DOOR_DIST)
					&& (y < i + DOOR_DIST && y > i - DOOR_DIST))
					lst->map[i][j] = 'p';
				else
					lst->map[i][j] = 'P';
			}
		}
	}
}

void	move_player(t_map *lst, double ang)
{
	double	xspd;
	double	yspd;

	xspd = cos(torad(ang)) * PLR_SPEED;
	yspd = sin(torad(ang)) * PLR_SPEED;
	while (lst->map[(int)(lst->py + yspd)]
		[(int)(lst->px + xspd)] == '1')
	{
		xspd -= cos(torad(ang)) * PLR_SPEED / 5;
		yspd -= sin(torad(ang)) * PLR_SPEED / 5;
	}
	lst->px += xspd;
	lst->py += yspd;
	check_door(lst);
}

void	move_camera(t_map *lst)
{
	lst->dir_x = cos(torad(lst->angle));
	lst->dir_y = sin(torad(lst->angle));
	lst->plane_x = -lst->dir_y * tan(torad(80 / 2));
	lst->plane_y = lst->dir_x * tan(torad(80 / 2));
}

int	controle(int key, t_map *lst)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_DOWN || key == K_UP || key == K_LEFT || key == K_RIGHT)
		move_player(lst, lst->angle - (key == K_LEFT)
			* 90 + (key == K_DOWN) * 180 + (key == K_RIGHT) * 90);
	if (key == K_L_RIGHT)
		lst->angle += PLR_TURN;
	if (key == K_L_LEFT)
		lst->angle -= PLR_TURN;
	if (key == K_MOUSE)
		lst->mouse_mode = !lst->mouse_mode;
	return (0);
}

void	do_mouse(t_map *lst)
{
	int			x;
	int			y;

	if (lst->mouse_mode)
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(lst->win, &x, &y);
		if (x != X_RES / 2)
		{
			lst->angle += (x - X_RES / 2) / 10;
			mlx_mouse_move(lst->win, X_RES / 2, Y_RES / 2);
		}
		mlx_mouse_move(lst->win, X_RES / 2, Y_RES / 2);
	}
	else
		mlx_mouse_show();
}
