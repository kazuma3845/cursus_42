/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:25:48 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/20 16:54:33 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	start_game(t_game info)
{

	info.mlxpointer = mlx_init();
	info.winpointer = mlx_new_window(info.mlxpointer, info.col * 40, info.ligne * 40,
			"so_long");
	printf("%s", info.map[0]);
	image(&info);
	add_image_window(&info);
	// mlx_key_hook(info.winpointer, controle, &info);
	// mlx_hook(info.winpointer, 27, 0, (void *)exit, 0);
	mlx_loop(info.mlxpointer);
}

void	place_player(int ligne, int col, t_game *info)
{
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->player,
			col * 40, ligne * 40);
		info->x = col;
		info->y = ligne;
}

void	place_item(int ligne, int col, t_game *info)
{
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->item,
			col * 40, ligne * 40);
		info->nbr_item++;
}

void	add_image_window2(t_game *info, int ligne, int col)
{
	if (info->map[ligne][col] == '1')
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->wall,
			col * 40, ligne * 40);
	if (info->map[ligne][col] == '0')
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->floor,
			col * 40, ligne * 40);
	if (info->map[ligne][col] == 'P')
			place_player(ligne, col, info);
	if (info->map[ligne][col] == 'C')
		place_item(ligne, col, info);
	if (info->map[ligne][col] == 'E')
		mlx_put_image_to_window(info->mlxpointer, info->winpointer, info->exit,
			col * 40, ligne * 40);
}

void	add_image_window(t_game *info)
{
	size_t	ligne;
	size_t	col;

	ligne = 0;
	info->nbr_item = 0;
	while (ligne != info->ligne)
	{
		col = 0;
		while (info->map[ligne][col] != '\n' && info->map[ligne][col] != '\0')
		{
			add_image_window2(info, ligne, col);
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
	info->player = mlx_xpm_file_to_image(info->mlxpointer, "texture/player.xpm",
			&i, &j);
	info->wall = mlx_xpm_file_to_image(info->mlxpointer, "texture/wall.xpm", &i,
			&j);
	info->floor = mlx_xpm_file_to_image(info->mlxpointer, "texture/floor.xpm",
			&i, &j);
}
