/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:57:49 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/17 15:59:33 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
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
# include "mlx.h"

typedef struct s_map
{
	char	**map;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;

	void	*north;
	void	*south;
	void	*east;
	void	*west;
	void	*floor;
	void	*top;
	void	*door;
	void	*mlxpointer;
	void	*winpointer;
}	t_map;


#endif