/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:05:19 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/15 10:57:29 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

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

// char_utils.c
bool	in_charset(char c, char *charset);

// free_utils.c
char	**free_str_tab(char	**tab);
bool	unexpected_line_error(t_cub3d *cub3d);
int		exit_cub3d(t_cub3d *cub3d, int exit_code);

// gc.c
void	clear_gc(t_gc *gc);
void	*add_gc(t_gc **gc, size_t nmemb, size_t size);

// init_utils.c
t_cub3d	*init_cub3d(void);

// math_utils.c
double	adjacent_opposite(double position, double angle, t_side side);
double	normalize_angle(double angle);
double	hypotenuse_len(t_cub3d *cub3d, double ray_angle);

// mlx_handlers.c
void	init_events(t_cub3d *cub3d);

// mlx_utils.c
void	set_pixel_color(t_img *img, int x, int y, unsigned long color);
void	color_column(t_cub3d *cub3d, int x);
void	draw_img(t_cub3d *cub3d);

// print_utils.c
void	ft_print_error(char *msg);

#endif
