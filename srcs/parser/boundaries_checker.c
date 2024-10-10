/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 02:20:07 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/10 03:05:37 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	**init_visited(unsigned long height, unsigned long width)
{
	bool			**visited;
	unsigned long	i;

	visited = ft_calloc(height, sizeof(bool *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = ft_calloc(width, sizeof(bool));
		if (!visited[i])
			return (free_visited(visited, height));
		i++;
	}
	return (visited);
}

static void	flood_fill(t_cub3d *cub3d, unsigned long x, unsigned long y,
	bool **visited)
{
	t_map	*map;
	char	**array;

	map = cub3d->map;
	array = map->array;
	if (x >= map->height || y >= map->width
		|| visited[x][y] || in_charset(array[x][y], "1#"))
		return ;
	visited[x][y] = true;
	if (x)
		flood_fill(cub3d, x - 1, y, visited);
	flood_fill(cub3d, x + 1, y, visited);
	if (y)
		flood_fill(cub3d, x, y - 1, visited);
	flood_fill(cub3d, x, y + 1, visited);
}

static void	height_fill(t_cub3d *cub3d, bool **visited)
{
	unsigned long	x;
	t_map			*map;
	char			**array;

	x = 0;
	map = cub3d->map;
	array = map->array;
	while (x < map->height)
	{
		if (array[x][0] == '0' && !visited[x][0])
			flood_fill(cub3d, x, 0, visited);
		if (array[x][map->width - 1] == '0' && !visited[x][map->width - 1])
			flood_fill(cub3d, x, map->width - 1, visited);
		x++;
	}
}

static void	width_fill(t_cub3d *cub3d, bool **visited)
{
	unsigned long	y;
	t_map			*map;
	char			**array;

	y = 0;
	map = cub3d->map;
	array = map->array;
	while (y < map->width)
	{
		if (array[0][y] == '0' && !visited[0][y])
			flood_fill(cub3d, 0, y, visited);
		if (array[map->height - 1][y] == '0' && !visited[map->height - 1][y])
			flood_fill(cub3d, map->height - 1, y, visited);
		y++;
	}
}

bool	is_map_closed(t_cub3d *cub3d)
{
	bool			**visited;
	t_map			*map;
	unsigned long	x;
	unsigned long	y;

	map = cub3d->map;
	visited = init_visited(map->height, map->width);
	if (!visited)
		return (exit_cub3d(cub3d, EXIT_FAILURE), false);
	height_fill(cub3d, visited);
	width_fill(cub3d, visited);
	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->array[x][y] == '0' && !visited[x][y])
				return (free_visited(visited, map->height), false);
			y++;
		}
		x++;
	}
	free_visited(visited, map->height);
	return (true);
}
