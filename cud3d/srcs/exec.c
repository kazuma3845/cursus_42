/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:33:27 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/19 16:45:32 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int controle(int commande, t_map *lst)
{
	return (0);
}

void exec(t_map lst)
{
	lst.mlxpointer = mlx_init();
	lst.winpointer = mlx_new_window(lst.mlxpointer, (1280),
			(720), "Cub3D");
	// image(&lst);
	// add_image_window(&lst, 0);
	mlx_hook(lst.winpointer, 2, 0, controle, &lst);
	mlx_hook(lst.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(lst.mlxpointer);	
}
