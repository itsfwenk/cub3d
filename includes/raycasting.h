/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:48:22 by fli               #+#    #+#             */
/*   Updated: 2024/10/15 14:59:15 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

// Enums
typedef enum e_direction	t_direction;
typedef enum e_position		t_position;
typedef enum e_side			t_side;
typedef enum e_time			t_time;

// Structures
typedef struct s_gc			t_gc;
typedef struct s_img		t_img;
typedef struct s_line		t_line;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_raycaster	t_raycaster;
typedef struct s_cub3d		t_cub3d;

// init_raycaster.c
void	init_raycaster(t_cub3d *cub3d);

// init_window.c
void	init_window(t_cub3d *cub3d);

// raycasting.c
void	update_start_xy(t_cub3d *cub3d, double vector_x, double vector_y,
			t_side side);
void	get_in_tile_coordinate(t_cub3d *cub3d, double position,
			double ray_angle, t_side side);
double	wall_dist(t_cub3d *cub3d, double ray_angle);

#endif
