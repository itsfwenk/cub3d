/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:20:07 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/10 16:43:14 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	check_zero(char **map, unsigned long x, unsigned long y)
{
	unsigned long	height;
	unsigned long	width;
	char			tmp;

	if (map[x][y] != EMPTY)
		return (true);
	height = 0;
	while (map[height])
		height++;
	width = (unsigned long)ft_strlen(map[x]);
	if (y && y != width - 1)
		return (false);
	tmp = map[x][y];
	map[x][y] = WALL;
	if (!check_bounds(map, height, width))
		return (false);
	map[x][y] = tmp;
	return (true);
}

static bool	near_zero_or_player(t_cub3d *cub3d, unsigned long x,
	unsigned long y, bool essential)
{
	t_map			*map;
	char			**array;

	map = cub3d->map;
	array = map->array;
	array[x][y] = WALL;
	if (!essential)
		return (false);
	else if (x > 0 && in_charset(array[x - 1][y], "0P"))
		return (true);
	else if (x < map->height - 1 && in_charset(array[x + 1][y], "0P"))
		return (true);
	else if (y > 0 && in_charset(array[x][y - 1], "0P"))
		return (true);
	else if (y < map->width - 1 && in_charset(array[x][y + 1], "0P"))
		return (true);
	return (false);
}

bool	check_bounds(char **map, unsigned long height, unsigned long width)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < height)
	{
		if (!x || x == height - 1)
		{
			y = 0;
			while (map[x][y])
			{
				if (!in_charset(map[x][y], "1#") && !check_zero(map, x, y))
					return (false);
				y++;
			}
		}
		else if (!in_charset(map[x][0], "1#")
			|| !in_charset(map[x][width - 1], "1#"))
			return (false);
		x++;
	}
	return (true);
}

bool	is_map_closed(t_cub3d *cub3d)
{
	t_map			*map;
	char			**array;
	unsigned long	x;
	unsigned long	y;

	map = cub3d->map;
	array = map->array;
	if (!check_bounds(array, map->height, map->width))
		return (false);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (array[x][y] == IGNORE && near_zero_or_player(cub3d, x, y,
				(!x || x == map->height - 1 || !y || y == map->width - 1)))
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}
