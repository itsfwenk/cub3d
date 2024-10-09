/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:01:08 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 23:16:29 by mel-habi         ###   ########.fr       */
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
			if (line->line[i] == ' ')
				normalized[i] = '#';
			else
				normalized[i] = line->line[i];
			i++;
		}
		while (i < cub3d->map->width)
			normalized[i++] = '#';
		free(line->line);
		line->line = normalized;
		line = line->next;
	}
}
