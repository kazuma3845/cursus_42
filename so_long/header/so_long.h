/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:28 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/17 13:33:35 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"

typedef struct s_map
{
	int	p;
	int	c;
	int	e;
	int	ligne;
	int	col;
}		t_map;

int		main(int argc, char **argv);
char	**ft_read(char *file);
int		error_file(char *file);
int		error_car(char **map);
int		error_map(char **map);
int		error_size(char **map);
int		error_wall(char **map);
int		error_line(char **map);

#endif