/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:01:08 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/10 02:16:24 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_direction	get_direction(char c)
{
	if (c == 'E')
		return (EAST);
	else if (c == 'N')
		return (NORTH);
	else if (c == 'W')
		return (WEST);
	return (SOUTH);
}

void	normalize_map(t_cub3d *cub3d)
{
	t_line			*line;
	char			*normalized;
	unsigned long	i;

	line = cub3d->map->lines;
	while (line)
	{
		normalized = ft_calloc(cub3d->map->width + 1, sizeof(char));
		if (!normalized)
			exit_cub3d(cub3d, EXIT_FAILURE);
		i = 0;
		while (line->line[i])
		{
			if (line->line[i] == SPACE)
				normalized[i] = IGNORE;
			else
				normalized[i] = line->line[i];
			i++;
		}
		while (i < cub3d->map->width)
			normalized[i++] = IGNORE;
		free(line->line);
		line->line = normalized;
		line = line->next;
	}
}

void	lines_to_array(t_cub3d *cub3d)
{
	char			**array;
	t_line			*line;
	unsigned long	i;

	array = ft_calloc(cub3d->map->height + 1, sizeof(char *));
	if (!array)
		exit_cub3d(cub3d, EXIT_FAILURE);
	i = 0;
	line = cub3d->map->lines;
	while (i < cub3d->map->height)
	{
		array[i] = line->line;
		line = line->next;
		i++;
	}
	cub3d->map->array = array;
}
