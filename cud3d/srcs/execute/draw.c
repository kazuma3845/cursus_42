/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:33:14 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/26 09:50:40 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_draw(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_map *lst, int y_start, char *txt_col)
// can make the image into a struct, so it doesn't need to be created each frame
{
	int		x;
	int		y;
	t_image	img;
	int		col;

	col = get_color(txt_col);
	lst->img = mlx_new_image(lst->mlx, X_RES, Y_RES / 2);
	img.addr = mlx_get_data_addr(lst->img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = -1;
	while (++y < Y_RES / 2)
	{
		x = -1;
		while (++x < X_RES)
			pixel_draw(&img, x, y, col);
	}
	// while (++y < Y_RES)
	// {
	// 	x = -1;
	// 	while (++x < X_RES)
	// 		pixel_draw(&img, x, y, col);
	// }
	// mlx_put_image_to_window(lst->mlx, lst->win, img.img, 0, y_start);
}

void	draw_mmplayer(t_map *lst)
{
	double	x;
	double	y;

	x = lst->px * 10;
	y = lst->py * 10;
	mlx_put_image_to_window(lst->mlx, lst->win,
		lst->txtrs[SPR_MM_WPLAYER]->ptr, x - cos(torad(lst->angle)) * 2,
		y - sin(torad(lst->angle)) * 2);
	mlx_put_image_to_window(lst->mlx, lst->win,
		lst->txtrs[SPR_MM_WPLAYER]->ptr, x - cos(torad(lst->angle)) * 4,
		y - sin(torad(lst->angle)) * 4);
	mlx_put_image_to_window(lst->mlx, lst->win,
		lst->txtrs[SPR_MM_WPLAYER]->ptr, x + cos(torad(lst->angle)) * 2,
		y + sin(torad(lst->angle)) * 2);
	mlx_put_image_to_window(lst->mlx, lst->win,
		lst->txtrs[SPR_MM_RPLAYER]->ptr, x, y);
}

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
		draw_mmplayer(lst);
	}
}

void	render_frame(t_map *lst)
{
	// draw_background(lst, Y_RES / 2, lst->f_tex);
	// draw_background(lst, 0, lst->c_tex);
	raycasting(lst);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->img, 0, 0);
	draw_minimap(lst);
}
