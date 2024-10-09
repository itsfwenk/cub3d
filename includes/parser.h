/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:31:05 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 17:37:44 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// Enums
typedef enum e_direction	t_direction;
typedef enum e_position		t_position;

// Structures
typedef struct s_gc			t_gc;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_cub3d		t_cub3d;

// checker.c
bool	is_correct_filename(char *filename, char *extension);

// line_utils.c
bool	parse_simple_line(t_cub3d *cub3d, char **splitted, int fd,
			t_direction direction);
bool	parse_color_line(t_cub3d *cub3d, char **splitted, int fd,
			t_position position);

// parser.c
void	cub3d_parser(t_cub3d *cub3d, char *mappath);

#endif
