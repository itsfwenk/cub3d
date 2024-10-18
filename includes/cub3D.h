/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:03:22 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/18 17:23:03 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>

# include "libft.h"

# include "parser.h"
# include "raycasting.h"
# include "utils.h"

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define SPACE ' '
# define FLOOD_FILL_MARKED '#'
# define WIDTH 1680
# define HEIGHT 720
# define TILE_SIZE 64
# define PI 3.14159265358979323846

# define ROTATE_FORCE 0.2f
# define MOVEMENT_FORCE 0.3f

# define WIN_NAME "cub3D"

// Enums
typedef enum e_movement		t_movement;
typedef enum e_direction	t_direction;
typedef enum e_position		t_position;
typedef enum e_side			t_side;
typedef enum e_time			t_time;

typedef enum e_movement
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	C_LEFT,
	C_RIGHT
}	t_movement;

typedef enum e_direction
{
	EAST,
	NORTH,
	WEST,
	SOUTH
}	t_direction;

typedef enum e_position
{
	CEIL,
	FLOOR
}	t_position;

typedef enum e_side
{
	HORIZONTAL,
	VERTICAL
}	t_side;

typedef enum e_time
{
	OLDTIME,
	CURTIME
}	t_time;

// Structures
typedef struct s_gc			t_gc;
typedef struct s_img		t_img;
typedef struct s_line		t_line;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_raycaster	t_raycaster;
typedef struct s_cub3d		t_cub3d;

typedef struct s_gc
{
	void	*ptr;
	t_gc	*next;
}	t_gc;

typedef struct s_img
{
	void				*img_ptr;
	char				*addr;
	int					bits_per_pixel;
	int					line_len;
	int					endian;
}	t_img;

typedef struct s_line
{
	char	*line;
	t_line	*next;
}	t_line;

typedef struct s_map
{
	t_line				*lines;
	char				**array;
	unsigned long		height;
	unsigned long		width;
	char				*textures[4];
	unsigned long		colors[2];
}	t_map;

typedef struct s_player
{
	double				x;
	double				y;
	double				dir_x;
	double				dir_y;
	double				angle;
}	t_player;

typedef struct s_raycaster
{
	int				wd_x;
	int				wd_y;
	int				tile_x;
	int				tile_y;
	int				wall_start;
	int				wall_end;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				tex_x;
	int				tex_y;
	double			camera_x;
	double			plane_x;
	double			plane_y;
	double			wall_dist;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			ray_dir_x;
	double			ray_dir_y;
	double			wall_x;
	t_direction		tile_face;
}	t_raycaster;

typedef struct s_timedata
{
	suseconds_t	time;
	suseconds_t	old_time;
}	t_timedata;

typedef struct s_cub3d
{
	void				*connection;
	void				*win;
	double				time[2];
	char				*p_line;
	t_img				img;
	t_img				textures[4];
	t_player			*player;
	t_map				*map;
	t_raycaster			*raycaster;
	t_gc				*gc;
	t_timedata			*timedata;
}	t_cub3d;

#endif
