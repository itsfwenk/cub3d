/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:05:19 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 21:12:48 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

// Enums
typedef enum e_direction	t_direction;
typedef enum e_position		t_position;

// Structures
typedef struct s_gc			t_gc;
typedef struct s_img		t_img;
typedef struct s_line		t_line;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
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

// print_utils.c
void	ft_print_error(char *msg);

#endif
