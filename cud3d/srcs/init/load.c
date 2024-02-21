/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:32:44 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/21 13:56:36 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_map *data, int spr_ind, char *spr)
{
	data->txtrs[spr_ind]->ptr = mlx_xpm_file_to_image(data->mlx,
			spr, &data->txtrs[spr_ind]->width, &data->txtrs[spr_ind]->height);
}

void	load_all_textures(t_map *data)
{
	int	i;

	i = 0;
	while (i < SPR_NBR)
	{
		data->txtrs[i] = malloc(sizeof(t_txtr));
		if (!data->txtrs[i])
			exit(1);
		i += 1;
	}
	load_texture(data, SPR_NORTH, data->n_tex);
	load_texture(data, SPR_WEST, data->w_tex);
	load_texture(data, SPR_EAST, data->e_tex);
	load_texture(data, SPR_SOUTH, data->s_tex);
	load_texture(data, SPR_MM_BLACK, "texture/mm_black.xpm");
	load_texture(data, SPR_MM_GREY, "texture/mm_grey.xpm");
	load_texture(data, SPR_MM_PLAYER, "texture/mm_player.xpm");
}
