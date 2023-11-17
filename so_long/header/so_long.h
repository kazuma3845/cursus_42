/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 14:17:39 by tomuller         ###   ########.fr       */
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

int			main(int argc, char **argv);
char		**ft_read(char *file);
int			error_file(char *file);
int			error_car(char **map);
int			error_map(char **map);
int			error_size(char **map);
int			error_wall(char **map);
int			error_line(char **map);
size_t		ft_strlen(const char *s);

#endif