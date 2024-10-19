/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:07:53 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/19 14:13:58 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_cub3d	*init_cub3d(void)
{
	t_gc	*gc;
	t_cub3d	*cub3d;

	gc = NULL;
	cub3d = add_gc(&gc, 1, sizeof(t_cub3d));
	cub3d->player = add_gc(&gc, 1, sizeof(t_player));
	cub3d->map = add_gc(&gc, 1, sizeof(t_map));
	cub3d->raycaster = add_gc(&gc, 1, sizeof(t_raycaster));
	cub3d->map->colors[0] = LONG_MAX;
	cub3d->map->colors[1] = LONG_MAX;
	cub3d->gc = gc;
	return (cub3d);
}
