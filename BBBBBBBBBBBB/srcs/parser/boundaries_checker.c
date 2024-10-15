/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:20:07 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/10 10:45:23 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	check_bounds(char **map, unsigned long height, unsigned long width)
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
				if (!in_charset(map[x][y], "1#"))
					return (false);
				y++;
			}
		}
		if (!in_charset(map[x][0], "1#")
			|| !in_charset(map[x][width - 1], "1#"))
			return (false);
		x++;
	}
	return (true);
}

static bool	near_zero(t_cub3d *cub3d, unsigned long x, unsigned long y)
{
	t_map			*map;
	char			**array;

	map = cub3d->map;
	array = map->array;
	if (x > 0 && array[x - 1][y] == EMPTY)
		return (true);
	else if (x < map->height - 1 && array[x + 1][y] == EMPTY)
		return (true);
	else if (y > 0 && array[x][y - 1] == EMPTY)
		return (true);
	else if (y < map->width - 1 && array[x][y + 1] == EMPTY)
		return (true);
	array[x][y] = WALL;
	return (false);
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
			if (array[x][y] == '#' && near_zero(cub3d, x, y))
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}
