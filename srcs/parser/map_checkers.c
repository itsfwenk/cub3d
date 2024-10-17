/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:39:19 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 18:43:56 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	check_line(t_cub3d *cub3d, t_line *line, unsigned long x,
	bool *player_put)
{
	unsigned long	y;

	y = 0;
	while (y < cub3d->map->width)
	{
		if (!in_charset(line->line[y], "NSEW01"))
			return (ft_print_error("There is one bad character on this map"),
				false);
		else if (in_charset(line->line[y], "NSEW"))
		{
			if (*player_put)
				return (ft_print_error("A player is already put on this map"),
					false);
			*player_put = true;
			cub3d->player->x = y + 0.5;
			cub3d->player->y = x + 0.5;
			cub3d->player->angle = get_direction(line->line[y]) * 90;
			line->line[y] = PLAYER;
		}
		y++;
	}
	return (true);
}

static void	put_player(t_cub3d *cub3d)
{
	unsigned long	x;
	bool			player_put;
	t_line			*line;

	x = 0;
	player_put = false;
	line = cub3d->map->lines;
	while (line)
	{
		if (!check_line(cub3d, line, x, &player_put))
			exit_cub3d(cub3d, EXIT_FAILURE);
		x++;
		line = line->next;
	}
	if (!player_put)
	{
		ft_print_error("There is no player on this map");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
}

static bool	flood_fill(t_cub3d *cub3d, unsigned long x, unsigned long y)
{
	t_map	*map;
	char	**array;

	map = cub3d->map;
	array = map->array;
	if (!in_charset(array[x][y], "P0"))
		return (true);
	else if (array[x][y] == EMPTY)
		array[x][y] = FLOOD_FILL_MARKED;
	if (!x || x == map->height - 1 || !y || y == map->width - 1)
		return (false);
	return (flood_fill(cub3d, x - 1, y)
		&& flood_fill(cub3d, x + 1, y)
		&& flood_fill(cub3d, x, y - 1)
		&& flood_fill(cub3d, x, y + 1));
}

static void	remove_flood_fill_markers(char **array, unsigned long height,
	unsigned long width)
{
	unsigned long	x;
	unsigned long	y;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (array[x][y] == FLOOD_FILL_MARKED)
				array[x][y] = EMPTY;
			y++;
		}
		x++;
	}
}

void	check_map(t_cub3d *cub3d)
{
	t_player	*player;
	t_map		*map;

	put_player(cub3d);
	player = cub3d->player;
	if (!flood_fill(cub3d, player->x, player->y))
	{
		ft_print_error("Map must be closed/\
the player can't go out of the map");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	map = cub3d->map;
	remove_flood_fill_markers(map->array, map->height, map->width);
}
