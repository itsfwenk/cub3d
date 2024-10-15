/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:19:53 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/15 19:49:12 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_dir(t_cub3d *cub3d)
{
	if (cub3d->player->angle == 0)
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
		cub3d->raycaster->plane_x = 0;
		cub3d->raycaster->plane_y = 0.66;
	}
	if (cub3d->player->angle == 90)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
		cub3d->raycaster->plane_x = 0.66;
		cub3d->raycaster->plane_y = 0;
	}
	if (cub3d->player->angle == 180)
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
		cub3d->raycaster->plane_x = 0;
		cub3d->raycaster->plane_y = 0.66;
	}
	if (cub3d->player->angle == 270)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
		cub3d->raycaster->plane_x = 0.66;
		cub3d->raycaster->plane_y = 0;
	}
}

void	init_raycaster(t_cub3d *cub3d)
{
	cub3d->raycaster->tile_x = cub3d->player->x;
	cub3d->raycaster->tile_y = cub3d->player->y;
	cub3d->raycaster->start_x = cub3d->player->in_tile_x;
	cub3d->raycaster->start_y = cub3d->player->in_tile_y;
	cub3d->raycaster->wall_dist = hypotenuse_len(cub3d,
			cub3d->raycaster->ray_angle);
	if (cub3d->raycaster->wall_dist < 0)
	{
		cub3d->raycaster->wall_dist = -cub3d->raycaster->wall_dist;
		get_in_tile_coordinate(cub3d, cub3d->player->in_tile_x,
			cub3d->raycaster->ray_angle, VERTICAL);
	}
	else
		get_in_tile_coordinate(cub3d, cub3d->player->in_tile_y,
			cub3d->raycaster->ray_angle, HORIZONTAL);
}
