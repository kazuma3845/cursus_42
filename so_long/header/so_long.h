/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/21 15:43:20 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	void	*wall;
	void	*player;
	void	*floor;
	void	*item;
	void	*exit;
	void	*mlxpointer;
	void	*winpointer;

	char	**map;

	int		p;
	int		c;
	int		e;
	int		x;
	int		y;
	int		y_max;
	int		x_max;
	int		nbr_item;
}			t_game;

int	main(int argc, char *argv[]);
void	ft_read(char *file, t_game *map);
int	error_file(char *file);
int	error_map(t_game *x);
void	start_game(t_game info);
void	add_image_window(t_game *info);
void	image(t_game *info);
int	controle(int commande, t_game *map);
void	fonc_exit(t_game *map);
int	left(t_game *map, int commande);
int	right(t_game *map, int commande);
int	up(t_game *map, int commande);
int	down(t_game *map, int commande);

#endif