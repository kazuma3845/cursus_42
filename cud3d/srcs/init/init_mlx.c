/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:37 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/22 14:41:24 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_map *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		printf("Malloc error");
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
		printf("Erreur d'initialisation MLX");
	game->mlx->win = mlx_new_window(game->mlx->mlx, X_RES, Y_RES, "Cube");
	if (!game->mlx->win)
		printf("Erreur de création de la fenêtre");
	game->mlx->img = mlx_new_image(game->mlx->mlx, X_RES, Y_RES);
	if (!game->mlx->img)
		printf("Erreur de création de l'image");
	game->mlx->addr = mlx_get_data_addr(game->mlx->img, &game->mlx->bpp,
			&game->mlx->len, &game->mlx->endian);
	if (!game->mlx->addr)
		printf("Erreur de récupération de l'adresse de l'image");
}
