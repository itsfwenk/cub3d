/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:28:48 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/18 13:50:49 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned long	get_color(char **splitted_color)
{
	unsigned long	r;
	unsigned long	g;
	unsigned long	b;

	r = ft_atoc(splitted_color[0]);
	if (r == LONG_MAX)
		return (LONG_MAX);
	g = ft_atoc(splitted_color[1]);
	if (g == LONG_MAX)
		return (LONG_MAX);
	b = ft_atoc(splitted_color[2]);
	if (b == LONG_MAX)
		return (LONG_MAX);
	return (r << 16 | g << 8 | b);
}

static char	*join_colors(t_cub3d *cub3d, char **splitted, int fd)
{
	char	*joined;
	char	*tmp;
	size_t	i;

	i = 2;
	joined = splitted[1];
	while (splitted[i])
	{
		tmp = joined;
		joined = ft_strjoin(joined, splitted[i]);
		if (!joined)
		{
			free_str_tab(splitted);
			close(fd);
			exit_cub3d(cub3d, EXIT_FAILURE);
			return (NULL);
		}
		free(tmp);
		i++;
	}
	return (joined);
}

bool	parse_simple_line(t_cub3d *cub3d, char **splitted, int fd,
			t_direction direction)
{
	char	*dup;

	if (splitted[2])
	{
		free_str_tab(splitted);
		return (false);
	}
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

	splitted[1] = join_colors(cub3d, splitted, fd);
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
		return (free_str_tab(splitted_color), free_str_tab(splitted), true);
	}
	free_str_tab(splitted_color);
	free_str_tab(splitted);
	return (false);
}
