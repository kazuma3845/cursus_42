/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:13:22 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/22 13:30:02 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_nsew(t_map *game)
{
	int	size;

	size = TEX_SIZE;
	game->texture->n_addr = mlx_get_data_addr(game->txtrs[0],
			&game->texture->n_bpp, &game->texture->n_len, &game->texture->n_endian);
	game->texture->s_addr = mlx_get_data_addr(game->txtrs[3],
			&game->texture->s_bpp, &game->texture->s_len, &game->texture->s_endian);
	game->texture->e_addr = mlx_get_data_addr(game->txtrs[2],
			&game->texture->e_bpp, &game->texture->e_len, &game->texture->e_endian);
	game->texture->w_addr = mlx_get_data_addr(game->txtrs[1],
			&game->texture->w_bpp, &game->texture->w_len, &game->texture->w_endian);
}

// static void	set_floor(t_map *game)
// {
// 	int	size;

// 	size = TEX_SIZE;
// 	game->texture->f_img = mlx_xpm_file_to_image(game->mlx->mlx,
// 			game->f_tex, &size, &size);
// 	if (!game->texture->f_img)
// 		printf("Texture error floor");
// 	game->texture->f_addr = mlx_get_data_addr(game->texture->f_img,
// 			&game->texture->f_bpp, &game->texture->f_len, &game->texture->f_endian);
// }

// static void	set_ceil(t_map *game)
// {
// 	int	size;

// 	size = TEX_SIZE;
// 	game->texture->f_img = mlx_xpm_file_to_image(game->mlx->mlx,
// 			game->c_tex, &size, &size);
// 	if (!game->texture->f_img)
// 		printf("Texture error ceil");
// 	game->texture->f_addr = mlx_get_data_addr(game->texture->f_img,
// 			&game->texture->f_bpp, &game->texture->f_len, &game->texture->f_endian);
// }

void	init_textures(t_map *game)
{
	game->texture = malloc(sizeof(t_texture));
	set_nsew(game);
	// set_floor(game);
	// set_ceil(game);
}
