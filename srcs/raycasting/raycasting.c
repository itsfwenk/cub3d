/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:51:44 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 18:29:41 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_step_sidedist(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y)
{
	printf("player->x = %f tile_x = %d delta_dist_x = %f\n", cub3d->player->x, cub3d->raycaster->tile_x, cub3d->raycaster->delta_dist_x);
	// printf("player->y = %f tile_y = %d delta_dist_y = %f\n", cub3d->player->y, cub3d->raycaster->tile_y, cub3d->raycaster->delta_dist_y);
	if (ray_dir_x < 0)
	{
		cub3d->raycaster->step_x = -1;
		cub3d->raycaster->side_dist_x = (cub3d->player->x
				- (double)cub3d->raycaster->tile_x)
				* cub3d->raycaster->delta_dist_x;
	}
	else
	{
		cub3d->raycaster->step_x = 1;
		cub3d->raycaster->side_dist_x = ((double)cub3d->raycaster->tile_x
				+ 1.0 - cub3d->player->x) * cub3d->raycaster->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		cub3d->raycaster->step_y = -1;
		cub3d->raycaster->side_dist_y = (cub3d->player->y
				- (double)cub3d->raycaster->tile_y)
				* cub3d->raycaster->delta_dist_y;
	}
	else
	{
		cub3d->raycaster->step_y = 1;
		cub3d->raycaster->side_dist_y = ((double)cub3d->raycaster->tile_y
				+ 1.0 - cub3d->player->y) * cub3d->raycaster->delta_dist_y;
	}
	// printf("%f %f\n", cub3d->raycaster->side_dist_x, cub3d->raycaster->side_dist_y);
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
		// printf("rc->side_dist_x = %f rc->side_dist_y = %f \n", rc->side_dist_x, rc->side_dist_y);
	}
}

void	init_raycaster(t_cub3d *cub3d)
{
	t_raycaster	*rc;

	rc = cub3d->raycaster;
	rc->camera_x = 2 * (double)rc->wd_x / (double)WIDTH - 1;
	// printf("%f\n", rc->camera_x);
	rc->ray_dir_x = cub3d->player->dir_x + rc->plane_x * rc->camera_x * (-1);
	// printf("%f\n", rc->ray_dir_x);
	rc->ray_dir_y = (cub3d->player->dir_y + rc->plane_y * rc->camera_x) * (-1);
	// printf("%f\n", rc->ray_dir_y);
	// printf("rc->ray_dir_x = %f rc->ray_dir_y = %f\n", rc->ray_dir_x, rc->ray_dir_y);
	rc->tile_x = (int)(cub3d->player->x);
	rc->tile_y = (int)(cub3d->player->y);
	// printf("x = %d y = %d\n", rc->tile_x, rc->tile_y);
	if (rc->ray_dir_x != 0)
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	else
		rc->delta_dist_x = 1e30;
	if (rc->ray_dir_y != 0)
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	else
		rc->delta_dist_y = 1e30;
	// printf("deltax = %f deltay = %f\n", rc->delta_dist_x, rc->delta_dist_y);
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
		// printf("rc->side = %d\n", rc->side);
	}
	else
	{
		// printf("rc->side != 0\n");
		if (rc->ray_dir_y > 0)
			rc->tile_face = SOUTH;
		else
			rc->tile_face = NORTH;
		rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
	}
	// printf("rc->side = %d\n", rc->side);
	// printf("rc->perp_wall_dist = %f\n", rc->perp_wall_dist);
	// printf("x = %d y = %d\n", rc->tile_x, rc->tile_y);
}
