/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:57:49 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/22 16:38:26 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
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

// Macro
# define K_ESC 53
# define K_UP 13
# define K_DOWN 1
# define K_LEFT 0
# define K_RIGHT 2
# define K_L_RIGHT 124
# define K_L_LEFT 123

# define X_RES 1280
# define Y_RES 720

# define SPR_NBR 8 // don't forget to update when adding sprites

# define SPR_NORTH 0
# define SPR_WEST 1
# define SPR_EAST 2
# define SPR_SOUTH 3
# define SPR_MM_BLACK 4
# define SPR_MM_GREY 5
# define SPR_MM_RPLAYER 6
# define SPR_MM_WPLAYER 7

# define PLR_SPEED 0.5 // absolute player speed
# define PLR_TURN 10   // How fast the player turns
# define TEX_SIZE 128

typedef struct s_txtr
{
	void		*ptr;
	int			width;
	int			height;
}				t_txtr;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_ray
{
	double		camera_x;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	double		perp_wall_dist;
	int			hit;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}				t_mlx;

typedef struct s_text
{
	int			bpp;
	int			len;
	char		*addr;
}				t_text;

typedef struct s_texture
{
	void		*n_img;
	int			n_bpp;
	char		*n_addr;
	int			n_len;
	int			n_endian;

	void		*s_img;
	int			s_bpp;
	char		*s_addr;
	int			s_len;
	int			s_endian;

	void		*e_img;
	int			e_bpp;
	char		*e_addr;
	int			e_len;
	int			e_endian;

	void		*w_img;
	int			w_bpp;
	char		*w_addr;
	int			w_len;
	int			w_endian;

	void		*f_img;
	int			f_bpp;
	char		*f_addr;
	int			f_len;
	int			f_endian;

	void		*c_img;
	int			c_bpp;
	char		*c_addr;
	int			c_len;
	int			c_endian;
}				t_texture;

typedef struct s_map
{
	char		**map;
	char		*n_tex;
	char		*s_tex;
	char		*e_tex;
	char		*w_tex;
	char		*f_tex;
	char		*c_tex;

	t_txtr		*txtrs[SPR_NBR];
	t_ray		*ray;
	t_mlx		*mlx;
	t_texture	*texture;

	double		px;
	double		py;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		angle;
	int			map_height;
	int			map_width;
}				t_map;

// main
int				main(int argc, char **argv);

// init_map
bool			check_line(t_map *lst, char *line);
void			copy_tab(t_map *lst, char *line, int ligne);
void			init_texture(t_map *lst, int i);
void			init_tab(t_map *lst, char *argv);
bool			check_arg(char *argv);

// parsing
bool			parsing(t_map *lst);
bool			map_error(t_map *lst);
void			change_map(t_map *lst);

// check
bool			check_vide(t_map *lst);
bool			touch_zero(t_map *lst, int line, int col);
bool			check_wall(t_map *lst);
bool			check_char(t_map *lst, int i);
bool			check_texture(t_map *lst);

// exec
void			exec(t_map *lst);

// clean
void			free_tab(char **tab);
void			clean_all(t_map *lst);

// load
void			load_all_textures(t_map *data);

// draw
void			draw_minimap(t_map *lst);
void			draw_background(t_map *lst, int y, char *txt_col);
void			render_frame(t_map *lst);

// raycasting text
int				calculate_tex_y(t_ray *ray, int y);
int				calculate_tex_x(t_map *game, t_ray *ray);
void			add_texture(t_map *lst, t_ray *ray, int x);

// raycasting utils
void			init_ray(t_map *lst, t_ray *ray, int x);
int				handling_hud(int a, int b, char c);

// raycasting
void			raycasting(t_map *lst);

// init_player
void			create_player(t_map *data);

void			init_mlx(t_map *game);

void			init_textures(t_map *game);

double			torad(double ang);
int				sign(int a);
int				get_color(char *col);

#endif