/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:33:27 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 09:46:18 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_map *lst, double ang)
{
	double	xspd;
	double	yspd;

	xspd = -(cos(torad(ang)) * PLR_SPEED);
	yspd = -(sin(torad(ang)) * PLR_SPEED);
	while (lst->map[(int)(lst->py + yspd)]
		[(int)(lst->px + xspd)] == '1')
	{
		xspd += cos(torad(ang)) * PLR_SPEED / 5;
		yspd += sin(torad(ang)) * PLR_SPEED / 5;
	}
	lst->px += xspd;
	lst->py += yspd;
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
	return (0);
}

void	do_mouse(t_map *lst)
{
	int			x;
	int			y;

	mlx_mouse_hide();
	mlx_mouse_get_pos(lst->win, &x, &y);
	if (x != X_RES / 2)
	{
		lst->angle += sign(x - X_RES / 2) * PLR_TURN / 3;
		mlx_mouse_move(lst->win, X_RES / 2, Y_RES / 2);
	}
	mlx_mouse_move(lst->win, X_RES / 2, Y_RES / 2);
}

int	game(t_map *lst)
{
	
	do_mouse(lst);
	render_frame(lst);
	return (0);
}

void	exec(t_map *lst)
{
	init_mlx(lst);
	load_all_textures(lst);
	mlx_loop_hook(lst->mlx, game, lst);
	mlx_hook(lst->win, 2, 0, controle, lst);
	mlx_hook(lst->win, 17, 0, (void *)exit, 0);
	draw_minimap(lst);
	mlx_loop(lst->mlx);
}
