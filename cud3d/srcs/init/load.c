/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:32:44 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/27 13:06:23 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_map *data, int spr_ind, char *spr)
{	
	int	size;

	size = TEX_SIZE;
	data->txtrs[spr_ind]->ptr = mlx_xpm_file_to_image(data->mlx,
			spr, &size, &size);
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
		data->txtrs[i]->ptr = NULL;
		i += 1;
	}
	load_texture(data, SPR_NORTH, data->n_tex);
	load_texture(data, SPR_WEST, data->w_tex);
	load_texture(data, SPR_EAST, data->e_tex);
	load_texture(data, SPR_SOUTH, data->s_tex);
	load_texture(data, SPR_MM_BLACK, "texture/mm_black.xpm");
	load_texture(data, SPR_MM_GREY, "texture/mm_grey.xpm");
	load_texture(data, SPR_MM_RPLAYER, "texture/mm_rplayer.xpm");
	load_texture(data, SPR_MM_WPLAYER, "texture/mm_wplayer.xpm");
	load_texture(data, SPR_MM_DOOR, "texture/mm_door.xpm");
	load_texture(data, SPR_DOOR, "texture/door_on.xpm");
	init_textures(data);
}
