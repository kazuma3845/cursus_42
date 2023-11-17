/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 16:25:06 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int		p;
	int		c;
	int		e;
	size_t	ligne;
	size_t	col;
}			t_map;
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
	int		x;
	int		y;
}			t_game;

int			main(int argc, char **argv);
char		**ft_read(char *file);
int			error_file(char *file);
int			error_car(t_game x);
int			error_map(t_game x);
int			error_size(t_game x);
int			error_wall(t_game x);
int			error_line(t_game x);

#endif