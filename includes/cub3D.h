/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:03:22 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 18:56:54 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>

# include "libft.h"

# include "parser.h"
# include "utils.h"

// Enums
typedef enum e_direction	t_direction;
typedef enum e_position		t_position;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_direction;

typedef enum e_position
{
	FLOOR,
	CEIL
}	t_position;

// Structures
typedef struct s_gc			t_gc;
typedef struct s_img		t_img;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
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

typedef struct s_map
{
	char				**array;
	char				*textures[4];
	unsigned long		colors[2];
}	t_map;

typedef struct s_player
{
	double				x;
	double				y;
	double				angle;
}	t_player;

typedef struct s_cub3d
{
	void				*connection;
	void				*win;
	t_img				img;
	t_player			*player;
	t_map				*map;
	t_gc				*gc;
}	t_cub3d;

#endif
