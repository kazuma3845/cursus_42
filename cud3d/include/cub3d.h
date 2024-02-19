/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:57:49 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/19 15:07:50 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	char	*f_texture;
	char	*c_texture;

	void	*north;
	void	*south;
	void	*east;
	void	*west;
	void	*floor;
	void	*top;
	void	*door;
	void	*mlxpointer;
	void	*winpointer;
}			t_map;

// init_map
void		init_tab(t_map *lst, char *argv);
void		init_texture(t_map *lst, int i);
bool		check_line(char *line);
bool		check_arg(char *argv);

// parsing
bool		parsing(t_map *lst);

// check
bool		check_vide(t_map *lst);
bool		check_wall(t_map *lst);
bool	check_char(t_map *lst, int i);
bool		check_texture(t_map *lst);

// clean
void		free_tab(char **tab);
void		clean_all(t_map *lst);
void		free_map(char **tab);

#endif