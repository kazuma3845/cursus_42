/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:33:27 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/21 16:23:26 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	controle(int key, t_map *lst)
{
	(void)lst;
	if (key == K_ESC)
		exit(0);
	if (key == K_DOWN)
		lst->py += PLR_SPEED;
	if (key == K_UP)
		lst->py -= PLR_SPEED;
	if (key == K_LEFT)
		lst->px -= PLR_SPEED;
	if (key == K_RIGHT)
		lst->px += PLR_SPEED;
	// draw_minimap(lst);
	return (0);
}

int game(t_map *lst)
{
	raycasting(lst);
	return (0);
}

void	exec(t_map *lst)
{
	lst->mlx = mlx_init();
	lst->win = mlx_new_window(lst->mlx, (X_RES), (Y_RES), "Cub3D");
	load_all_textures(lst);
	mlx_loop_hook(lst->mlx, game, &lst);
	mlx_hook(lst->win, 2, 0, controle, lst);
	mlx_hook(lst->win, 17, 0, (void *)exit, 0);
	// draw_minimap(lst);
	mlx_loop(lst->mlx);
}
