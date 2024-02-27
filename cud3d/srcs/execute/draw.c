/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreichel <nreichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:33:14 by nreichel          #+#    #+#             */
/*   Updated: 2024/02/27 13:17:50 by nreichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_draw(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_map *lst, char *ceil_txt, char *floor_txt)
// can make the image into a struct, so it doesn't need to be created each frame
{
	int		x;
	int		y;
	t_image	img;
	int		flr;
	int		ceil;

	flr = get_color(floor_txt);
	ceil = get_color(ceil_txt);
	img.img = mlx_new_image(lst->mlx, X_RES, Y_RES / 2);
	img.addr = mlx_get_data_addr(lst->img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = -1;
	while (++y < Y_RES / 2)
	{
		x = -1;
		while (++x < X_RES)
			pixel_draw(&img, x, y, ceil);
	}
	while (++y < Y_RES)
	{
		x = -1;
		while (++x < X_RES)
			pixel_draw(&img, x, y, flr);
	}
}

void	draw_mmplayer(t_map *lst, int sx, int sy)
{
	double	x;
	double	y;

	x = (lst->px - sx) * 10;
	y = (lst->py - sy) * 10;
	mlx_put_image_to_window(lst->mlx, lst->win, lst->txtrs[SPR_MM_WPLAYER]->ptr,
		x - cos(torad(lst->angle)) * 2, y - sin(torad(lst->angle)) * 2);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->txtrs[SPR_MM_WPLAYER]->ptr,
		x + cos(torad(lst->angle)) * 4, y + sin(torad(lst->angle)) * 4);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->txtrs[SPR_MM_WPLAYER]->ptr,
		x + cos(torad(lst->angle)) * 2, y + sin(torad(lst->angle)) * 2);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->txtrs[SPR_MM_RPLAYER]->ptr,
		x, y);
}

void	set_start_mm(t_map *lst, int *x, int *y)
{
	if ((int)lst->py < MM_HEIGHT / 2 || lst->map_height <= MM_HEIGHT)
		*y = 0;
	else if ((int)lst->py > lst->map_height - MM_HEIGHT / 2)
		*y = lst->map_height - MM_HEIGHT;
	else
		*y = (int)lst->py - MM_HEIGHT / 2;
	if ((int)lst->px < MM_WIDTH / 2 || lst->map_width <= MM_WIDTH)
		*x = 0;
	else if ((int)lst->px > lst->map_width - MM_WIDTH / 2)
		*x = lst->map_width - MM_WIDTH;
	else
		*x = (int)lst->px - MM_WIDTH / 2;
}

void	draw_minimap(t_map *lst)
{
	int	i;
	int	j;
	int	sx;
	int	sy;

	set_start_mm(lst, &sx, &sy);
	i = -1;
	while (lst->map[sy + ++i] && i < MM_HEIGHT)
	{
		j = -1;
		while (lst->map[sy + i][sx + ++j] && j < MM_WIDTH)
		{
			if (lst->map[sy + i][sx + j] == '0'
				|| lst->map[sy + i][sx + j] == 'p')
				mlx_put_image_to_window(lst->mlx, lst->win,
					lst->txtrs[SPR_MM_GREY]->ptr, j * 10, i * 10);
			if (lst->map[sy + i][sx + j] == '1')
				mlx_put_image_to_window(lst->mlx, lst->win,
					lst->txtrs[SPR_MM_BLACK]->ptr, j * 10, i * 10);
			if (lst->map[sy + i][sx + j] == 'P')
				mlx_put_image_to_window(lst->mlx, lst->win,
					lst->txtrs[SPR_MM_DOOR]->ptr, j * 10, i * 10);
		}
		draw_mmplayer(lst, sx, sy);
	}
}
