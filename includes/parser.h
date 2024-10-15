/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:31:05 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/14 19:14:27 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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

// checker.c
bool			is_correct_filename(char *filename, char *extension);
unsigned long	ft_atoc(char *nptr);

// line_utils.c
bool			parse_simple_line(t_cub3d *cub3d, char **splitted, int fd,
					t_direction direction);
bool			parse_color_line(t_cub3d *cub3d, char **splitted, int fd,
					t_position position);

// map_checkers.c
void			check_map(t_cub3d *cub3d);

// map_utils.c
t_direction		get_direction(char c);
void			normalize_map(t_cub3d *cub3d);
void			lines_to_array(t_cub3d *cub3d);

// parser.c
void			cub3d_parser(t_cub3d *cub3d, char *mappath);

// t_line.c
void			clear_lines(t_line *line);
t_line			*add_line(t_map *map, char *val);

#endif
