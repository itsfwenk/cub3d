/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:03:08 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 21:37:53 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_line	*line_get_last(t_line *line)
{
	while (line)
	{
		if (!line->next)
			return (line);
		line = line->next;
	}
	return (line);
}

static void	line_add_back(t_line **line, t_line *val)
{
	t_line	*last;

	last = line_get_last(*line);
	if (last)
		last->next = val;
	else
		*line = val;
}

void	clear_lines(t_line *line)
{
	t_line	*tmp;

	while (line)
	{
		tmp = line->next;
		if (line->line)
			free(line->line);
		free(line);
		line = tmp;
	}
}

t_line	*add_line(t_map *map, char *val)
{
	t_line			*new_line;
	unsigned long	len;

	new_line = ft_calloc(1, sizeof(t_line));
	if (!new_line)
		return (free(val), NULL);
	new_line->line = ft_strtrim(val, " \n");
	if (!new_line->line)
	{
		free(new_line);
		free(val);
		return (NULL);
	}
	free(val);
	line_add_back(&map->lines, new_line);
	len = (unsigned long)ft_strlen(new_line->line);
	map->height++;
	if (len > map->width)
		map->width = len;
	return (new_line);
}
