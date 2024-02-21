/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:33:14 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/21 15:04:35 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_map *lst)
{
	int	i;
	int	j;

	i = -1;
	while (lst->map[++i])
	{
		j = -1;
		while (lst->map[i][++j])
		{
			if (lst->map[i][j] == '0')
				mlx_put_image_to_window(lst->mlx, lst->win,
					lst->txtrs[SPR_MM_GREY]->ptr, j * 10, i * 10);
			if (lst->map[i][j] == '1')
				mlx_put_image_to_window(lst->mlx, lst->win,
					lst->txtrs[SPR_MM_BLACK]->ptr, j * 10, i * 10);
		}
		mlx_put_image_to_window(lst->mlx, lst->win,
			lst->txtrs[SPR_MM_PLAYER]->ptr, lst->px * 10, lst->py * 10);
	}
}
