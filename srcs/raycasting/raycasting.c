/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:51:44 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/16 13:33:39 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	vertical_update(t_cub3d *cub3d, double vector_y)
// {
// 	if (cos(cub3d->raycaster->ray_angle) > 0)
// 	{
// 		cub3d->raycaster->start_x = 0;
// 		cub3d->raycaster->tile_x++;
// 		cub3d->raycaster->tile_face = WEST;
// 	}
// 	else
// 	{
// 		cub3d->raycaster->start_x = 1;
// 		cub3d->raycaster->tile_x--;
// 		cub3d->raycaster->tile_face = EAST;
// 	}
// 	if (cub3d->raycaster->ray_angle == 0 || cub3d->raycaster->ray_angle == 180)
// 		return ;
// 	else if (sin(cub3d->raycaster->ray_angle) > 0)
// 		cub3d->raycaster->start_y = fabs(cub3d->raycaster->start_y - vector_y);
// 	else if (sin(cub3d->raycaster->ray_angle) < 0)
// 		cub3d->raycaster->start_y = fabs(cub3d->raycaster->start_y + vector_y);
// }

// static void	horizontal_update(t_cub3d *cub3d, double vector_x)
// {
// 	if (sin(cub3d->raycaster->ray_angle) > 0)
// 	{
// 		cub3d->raycaster->start_y = 1;
// 		cub3d->raycaster->tile_y--;
// 		cub3d->raycaster->tile_face = NORTH;
// 	}
// 	else
// 	{
// 		cub3d->raycaster->start_y = 0;
// 		cub3d->raycaster->tile_y++;
// 		cub3d->raycaster->tile_face = SOUTH;
// 	}
// 	if (cub3d->raycaster->ray_angle == 90 || cub3d->raycaster->ray_angle == 270)
// 		return ;
// 	else if (cos(cub3d->raycaster->ray_angle) > 0)
// 		cub3d->raycaster->start_x = fabs(cub3d->raycaster-> + vector_x);
// 	else if (cos(cub3d->raycaster->ray_angle) < 0)
// 		cub3d->raycaster->start_x = fabs(cub3d->raycaster->start_x - vector_x);
// }

// void	update_start_xy(t_cub3d *cub3d, double vector_x, double vector_y,
// 	t_side side)
// {
// 	if (side == VERTICAL)
// 	{
// 		vertical_update(cub3d, vector_y);
// 		return ;
// 	}
// 	horizontal_update(cub3d, vector_x);
// }

// void	get_in_tile_coordinate(t_cub3d *cub3d, double position,
// 	double ray_angle, t_side side)
// {
// 	double	hypotenuse;
// 	double	adjacent;
// 	double	opposite;

// 	hypotenuse = hypotenuse_len(cub3d, ray_angle);
// 	if (side == VERTICAL)
// 	{
// 		adjacent = adjacent_opposite(position, ray_angle, side);
// 		opposite = sqrt(pow(hypotenuse, 2) - pow(adjacent, 2));
// 	}
// 	else
// 	{
// 		opposite = adjacent_opposite(position, ray_angle, side);
// 		adjacent = sqrt(pow(hypotenuse, 2) - pow(opposite, 2));
// 	}
// 	update_start_xy(cub3d, adjacent, opposite, side);
// }

// double	wall_dist(t_cub3d *cub3d, double ray_angle)
// {
// 	double	side_dist;

// 	init_raycaster(cub3d);
// 	while (cub3d->map->array[cub3d->raycaster->tile_y][cub3d->raycaster->tile_x]
// 		!= WALL)
// 	{
// 		side_dist = hypotenuse_len(cub3d, ray_angle);
// 		if (side_dist < 0)
// 		{
// 			side_dist = -side_dist;
// 			get_in_tile_coordinate(cub3d, cub3d->player->in_tile_x,
// 				cub3d->raycaster->ray_angle, VERTICAL);
// 		}
// 		else
// 			get_in_tile_coordinate(cub3d, cub3d->player->in_tile_y,
// 				cub3d->raycaster->ray_angle, HORIZONTAL);
// 		cub3d->raycaster->wall_dist = cub3d->raycaster->wall_dist + side_dist;
// 	}
// 	return (cub3d->raycaster->wall_dist);
// }

