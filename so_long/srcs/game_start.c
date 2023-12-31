/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:25:48 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/27 15:38:56 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	start_game(t_game info)
{
	info.mlxpointer = mlx_init();
	info.winpointer = mlx_new_window(info.mlxpointer, (info.x_max * 50),
			(info.y_max * 50), "so_long");
	image(&info);
	add_image_window(&info, 0);
	mlx_hook(info.winpointer, 2, 0, controle, &info);
	mlx_hook(info.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(info.mlxpointer);
}

void	put_game(t_game *info, int nbr)
{
	char	*nbr_str;

	nbr_str = ft_itoa(nbr);
	mlx_string_put(info->mlxpointer, info->winpointer, 1 * 25, 1 * 25, 1,
		nbr_str);
	free(nbr_str);
}

void	add_image_window2(t_game *info, int ligne, int col, int nbr)
{
	if (info->map[ligne][col] == '1')
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->wall,
			col * 50, ligne * 50);
	if (info->map[ligne][col] == 'C')
	{
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->floor,
			col * 50, ligne * 50);
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->item,
			col * 50, ligne * 50);
		info->nbr_item++;
	}
	if (info->map[ligne][col] == 'P')
	{
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->floor,
			col * 50, ligne * 50);
		mlx_put_image_to_window(info->mlxpointer, info->winpointer,
			info->player, col * 50, ligne * 50);
		info->x = col;
		info->y = ligne;
	}
	if (info->map[ligne][col] == '0')
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->floor,
			col * 50, ligne * 50);
	put_game(info, nbr);
}

void	add_image_window(t_game *info, int nbr)
{
	int	ligne;
	int	col;

	ligne = 0;
	info->nbr_item = 0;
	while (ligne != info->y_max)
	{
		col = 0;
		while (info->map[ligne][col])
		{
			if (info->map[ligne][col] == 'E')
				mlx_put_image_to_window(info->mlxpointer, info->winpointer,
					info->exit, col * 50, ligne * 50);
			if (info->map[ligne][col] == 'M')
			{
				mlx_put_image_to_window(info->mlxpointer, info->winpointer,
					info->floor, col * 50, ligne * 50);
				mlx_put_image_to_window(info->mlxpointer, info->winpointer,
					info->mob, col * 50, ligne * 50);
			}
			add_image_window2(info, ligne, col, nbr);
			col++;
		}
		ligne++;
	}
}

void	image(t_game *info)
{
	int	i;
	int	j;

	info->exit = mlx_xpm_file_to_image(info->mlxpointer, "texture/exit.xpm", &i,
			&j);
	info->item = mlx_xpm_file_to_image(info->mlxpointer, "texture/item.xpm", &i,
			&j);
	info->player = mlx_xpm_file_to_image(info->mlxpointer, "texture/front.xpm",
			&i, &j);
	info->wall = mlx_xpm_file_to_image(info->mlxpointer, "texture/wall.xpm", &i,
			&j);
	info->floor = mlx_xpm_file_to_image(info->mlxpointer, "texture/floor.xpm",
			&i, &j);
	info->mob = mlx_xpm_file_to_image(info->mlxpointer, "texture/mob.xpm", &i,
			&j);
}
