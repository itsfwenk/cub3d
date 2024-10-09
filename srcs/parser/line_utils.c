/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:28:48 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 19:26:16 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned long	get_color(char **splitted_color)
{
	(void)splitted_color;
	return (LONG_MAX);
}

bool	parse_simple_line(t_cub3d *cub3d, char **splitted, int fd,
			t_direction direction)
{
	char	*dup;

	if (cub3d->map->textures[direction])
		return (free_str_tab(splitted), false);
	dup = ft_strtrim(splitted[1], " \n");
	if (!dup)
	{
		close(fd);
		free_str_tab(splitted);
		exit_cub3d(cub3d, EXIT_FAILURE);
		return (false);
	}
	cub3d->map->textures[direction] = dup;
	free_str_tab(splitted);
	return (true);
}

bool	parse_color_line(t_cub3d *cub3d, char **splitted, int fd,
			t_position position)
{
	char	**splitted_color;

	if (cub3d->map->colors[position] != LONG_MAX)
		return (free_str_tab(splitted), false);
	splitted_color = ft_split(splitted[1], ',');
	if (!splitted_color)
	{
		close(fd);
		free_str_tab(splitted);
		exit_cub3d(cub3d, EXIT_FAILURE);
		return (false);
	}
	if (splitted_color[0] && splitted_color[1] && splitted_color[2]
		&& !splitted_color[3])
	{
		cub3d->map->colors[position] = get_color(splitted_color);
		if (cub3d->map->colors[position] == LONG_MAX)
			return (free_str_tab(splitted_color), free_str_tab(splitted),
				false);
		return (true);
	}
	free_str_tab(splitted_color);
	free_str_tab(splitted);
	return (false);
}
