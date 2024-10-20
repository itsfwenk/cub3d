/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:48:22 by fli               #+#    #+#             */
/*   Updated: 2024/10/19 14:05:33 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

// Enums
typedef enum e_movement		t_movement;
typedef enum e_direction	t_direction;
typedef enum e_position		t_position;
typedef enum e_side			t_side;

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
void	init_dir(t_cub3d *cub3d);

// init_window.c
void	init_window(t_cub3d *cub3d);

// raycasting.c
void	init_step_sidedist(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y);
void	raycaster(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y);
void	init_raycaster(t_cub3d *cub3d);
void	calc_perp_dist(t_cub3d *cub3d);

#endif
