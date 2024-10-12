/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:39:19 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/12 16:36:33 by fli              ###   ########.fr       */
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
		if (!in_charset(line->line[y], "NSEW01#"))
			return (ft_print_error("There is one bad character on this map"),
				false);
		else if (in_charset(line->line[y], "NSEW"))
		{
			if (*player_put)
				return (ft_print_error("A player is already put on this map"),
					false);
			*player_put = true;
			cub3d->player->x = x;
			cub3d->player->y = y;
			cub3d->player->inTileX = 1 / 2;
			cub3d->player->inTileY = 1 / 2;
			cub3d->player->angle = get_direction(line->line[y]) * PI / 2;
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

void	check_map(t_cub3d *cub3d)
{
	put_player(cub3d);
	if (!is_map_closed(cub3d))
	{
		ft_print_error("Map must be closed");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
}
