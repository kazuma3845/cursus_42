/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:57:49 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/19 16:40:45 by tomuller         ###   ########.fr       */
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

//main
int	main(int argc, char **argv);

// init_map
bool		check_line(char *line);
void		copy_tab(t_map *lst, char *line, int ligne);
void		init_texture(t_map *lst, int i);
void		init_tab(t_map *lst, char *argv);
bool		check_arg(char *argv);

// parsing
bool		parsing(t_map *lst);
bool		map_error(t_map *lst);
void		change_map(t_map *lst);

// check
bool		check_vide(t_map *lst);
bool		touch_zero(t_map *lst, int line, int col);
bool		check_wall(t_map *lst);
bool		check_char(t_map *lst, int i);
bool		check_texture(t_map *lst);

// exec
void		exec(t_map lst);

// clean
void		free_tab(char **tab);
void		clean_all(t_map *lst);

#endif