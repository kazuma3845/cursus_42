/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:37 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/23 10:11:40 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_map *lst)
{
	lst->mlx = mlx_init();
	if (!lst->mlx)
		printf("Erreur d'initialisation MLX");
	lst->win = mlx_new_window(lst->mlx, X_RES, Y_RES, "Cube");
	if (!lst->win)
		printf("Erreur de création de la fenêtre");
	lst->img = mlx_new_image(lst->mlx, X_RES, Y_RES);
	if (!lst->img)
		printf("Erreur de création de l'image");
	lst->addr = mlx_get_data_addr(lst->img, &lst->bpp,
			&lst->len, &lst->endian);
	if (!lst->addr)
		printf("Erreur de récupération de l'adresse de l'image");
}
