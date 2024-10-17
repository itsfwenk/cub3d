/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:51:44 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 18:42:22 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_step_sidedist(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y)
{
	t_raycaster	*rc;
	t_player	*p;

	rc = cub3d->raycaster;
	p = cub3d->player;
	if (ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (p->x - (double)rc->tile_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = ((double)rc->tile_x + 1.0 - p->x) * rc->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (p->y - rc->tile_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = ((double)rc->tile_y + 1.0 - p->y) * rc->delta_dist_y;
	}
}

void	raycaster(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y)
{
	t_map		*map;
	t_raycaster	*rc;

	map = cub3d->map;
	rc = cub3d->raycaster;
	init_step_sidedist(cub3d, ray_dir_x, ray_dir_y);
	while (map->array[rc->tile_y][rc->tile_x] != WALL)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->tile_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->tile_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->tile_y > (int)map->height || rc->tile_x > (int)map->width)
			break ;
	}
}

void	init_raycaster(t_cub3d *cub3d)
{
	t_raycaster	*rc;

	rc = cub3d->raycaster;
	rc->camera_x = 2 * (double)rc->wd_x / (double)WIDTH - 1;
	rc->ray_dir_x = cub3d->player->dir_x + rc->plane_x * rc->camera_x * (-1);
	rc->ray_dir_y = (cub3d->player->dir_y + rc->plane_y * rc->camera_x) * (-1);
	rc->tile_x = (int)(cub3d->player->x);
	rc->tile_y = (int)(cub3d->player->y);
	if (rc->ray_dir_x != 0)
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	else
		rc->delta_dist_x = 1e30;
	if (rc->ray_dir_y != 0)
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	else
		rc->delta_dist_y = 1e30;
	rc->wall_dist = 0;
	rc->tile_face = 0;
}

void	calc_perp_dist(t_cub3d *cub3d)
{
	t_raycaster	*rc;

	rc = cub3d->raycaster;
	if (rc->side == 0)
	{
		if (rc->ray_dir_x > 0)
			rc->tile_face = EAST;
		else
			rc->tile_face = WEST;
		rc->perp_wall_dist = (rc->side_dist_x - rc->delta_dist_x);
	}
	else
	{
		if (rc->ray_dir_y > 0)
			rc->tile_face = SOUTH;
		else
			rc->tile_face = NORTH;
		rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
	}
}
