/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:33:27 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/26 13:33:20 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_map *lst)
{
	draw_background(lst, lst->c_tex, lst->f_tex);
	raycasting(lst);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->img, 0, 0);
	draw_minimap(lst);
}

int	game(t_map *lst)
{
	do_mouse(lst);
	move_camera(lst);
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
	mlx_mouse_move(lst->win, X_RES / 2, Y_RES / 2);
	mlx_loop(lst->mlx);
}
