/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:32:44 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 14:54:35 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_gc	*gc_get_last(t_gc *gc)
{
	while (gc)
	{
		if (!gc->next)
			return (gc);
		gc = gc->next;
	}
	return (gc);
}

static void	gc_add_back(t_gc **gc, t_gc *val)
{
	t_gc	*last;

	last = gc_get_last(*gc);
	if (last)
		last->next = val;
	else
		*gc = val;
}

void	clear_gc(t_gc *gc)
{
	t_gc	*tmp;

	while (gc)
	{
		tmp = gc->next;
		if (gc->ptr)
			free(gc->ptr);
		free(gc);
		gc = tmp;
	}
}

void	*add_gc(t_gc **gc, size_t nmemb, size_t size)
{
	t_gc	*new_gc;

	new_gc = ft_calloc(1, sizeof(t_gc));
	if (!new_gc)
	{
		clear_gc(*gc);
		exit(EXIT_FAILURE);
		return (NULL);
	}
	new_gc->ptr = ft_calloc(nmemb, size);
	if (!new_gc->ptr)
	{
		clear_gc(*gc);
		free(new_gc);
		exit(EXIT_FAILURE);
		return (NULL);
	}
	gc_add_back(gc, new_gc);
	return (new_gc->ptr);
}
