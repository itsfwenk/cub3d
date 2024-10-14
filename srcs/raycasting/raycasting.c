/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:05:17 by fli               #+#    #+#             */
/*   Updated: 2024/10/14 13:39:53 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	init_dir(t_cub3d *cub3d)
// {
// 	if (cub3d->player->angle == 0)
// 	{
// 		cub3d->player->dir_x = 1;
// 		cub3d->player->dir_y = 0;
// 	}
// 	if (cub3d->player->angle ==  90)
// 	{
// 		cub3d->player->dir_x = 0;
// 		cub3d->player->dir_y = 1;
// 	}
// 	if (cub3d->player->angle ==  180)
// 	{
// 		cub3d->player->dir_x = -1;
// 		cub3d->player->dir_y = 0;
// 	}
// 	if (cub3d->player->angle ==  270)
// 	{
// 		cub3d->player->dir_x = 0;
// 		cub3d->player->dir_y = -1;
// 	}
// }

// position = position in the current map cell
// angle = angle from 0 = rayAngle => to know which direction player is facing
// => gives opposite or adjacent length
double	adjacent_opposite(double position, double angle, t_side side)
{
	if (side == HORIZONTAL)
	{
		if (sin(angle) > 0)
			return (position);
		else
			return (1 - position);
	}
	if (side == VERTICAL)
	{
		if (cos(angle) > 0)
			return (1 - position);
		else
			return (position);
	}
}

double	normalize_angle(double angle)
{
	if (cos(angle) < 0 && sin(angle) > 0)
		return (angle - (PI / 2));
	else if (cos(angle) < 0 && sin(angle) < 0)
		return (angle - PI);
	else if (cos(angle) > 0 && sin(angle) < 0)
		return (angle - (3 * (PI / 2)));
	else
		return (angle);
}

double	hypotenuse_len(t_cub3d *cub3d, double rayAngle, double startX, double startY)
{
	double	vertHypo;
	double	horizHypo;
	double	normAngle;

	normAngle = normalize_angle(rayAngle);
	vertHypo = adjacent_opposite(cub3d->player->inTileX, rayAngle, VERTICAL) / sin(normAngle);
	horizHypo = adjacent_opposite(cub3d->player->inTileY, rayAngle, HORIZONTAL) / cos(normAngle);
	if (vertHypo < horizHypo)
		return (-1 * vertHypo);
	else
		return (horizHypo);
}

// void	update_tileX(double sideDist, double rayAngle, int *mapX, double *wallDist)
// {
// 		if (sideDist < 0 && cos(rayAngle) > 0)
// 		{
// 			mapX++;
// 			*wallDist = *wallDist - sideDist;
// 		}
// 		else if (sideDist < 0 && cos(rayAngle) < 0)
// 		{
// 			mapX--;
// 			*wallDist = *wallDist - sideDist;
// 		}
// }

// void	update_tileY(double sideDist, double rayAngle, int *mapY, double *wallDist)
// {
// 	if (sideDist > 0 && sin(rayAngle) > 0)
// 	{
// 		mapY--;
// 		*wallDist = *wallDist + sideDist;
// 	}
// 	else if (sideDist > 0 && sin(rayAngle) < 0)
// 	{
// 		mapY++;
// 		*wallDist = *wallDist + sideDist;
// 	}
// }

void	update_startXY(t_cub3d *cub3d, double vectorX, double vectorY, t_side side)
{
	if (side == VERTICAL)
	{
		if (cos(cub3d->raycaster->rayAngle) > 0)
		{
			cub3d->raycaster->startX = 0;
			cub3d->raycaster->tileX++;
			cub3d->raycaster->tileFace = WEST;
		}
		else
		{
			cub3d->raycaster->startX = 1;
			cub3d->raycaster->tileX--;
			cub3d->raycaster->tileFace = EAST;
		}
		if (cub3d->raycaster->rayAngle == 0 || cub3d->raycaster->rayAngle == 180)
			return ;
		else if (sin(cub3d->raycaster->rayAngle) > 0)
			cub3d->raycaster->startY = fabs(cub3d->raycaster->startY - vectorY);
		else if (sin(cub3d->raycaster->rayAngle) < 0)
			cub3d->raycaster->startY = fabs(cub3d->raycaster->startY + vectorY);

		return ;
	}
	if (side == HORIZONTAL)
	{

		if (sin(cub3d->raycaster->rayAngle) > 0)
		{
			cub3d->raycaster->startY = 1;
			cub3d->raycaster->tileY--;
			cub3d->raycaster->tileFace = NORTH;
		}
		else
		{
			cub3d->raycaster->startY = 0;
			cub3d->raycaster->tileY++;
			cub3d->raycaster->tileFace = SOUTH;
		}
		if (cub3d->raycaster->rayAngle == 90 || cub3d->raycaster->rayAngle == 270)
			return ;
		else if (cos(cub3d->raycaster->rayAngle) > 0)
			cub3d->raycaster->startX = fabs(cub3d->raycaster->startX + vectorX);
		else if (cos(cub3d->raycaster->rayAngle) < 0)
			cub3d->raycaster->startX = fabs(cub3d->raycaster->startX - vectorX);
		return ;
	}
}

void	get_inTile_coordinate(t_cub3d *cub3d, double position, double rayAngle, t_side side)
{
	double	hypotenuse;
	double	adjacent;
	double	opposite;

	hypotenuse = hypotenuse_len(cub3d, rayAngle, cub3d->raycaster->startX, cub3d->raycaster->startY);
	if (side == HORIZONTAL)
	{
		opposite = adjacent_opposite(position, rayAngle, side);
		adjacent = sqrt(pow(hypotenuse, 2) - pow(opposite, 2));
	}
	else if (side == VERTICAL)
	{
		adjacent = adjacent_opposite(position, rayAngle, side);
		opposite = sqrt(pow(hypotenuse, 2) - pow(adjacent, 2));
	}
	update_startXY(cub3d, adjacent, opposite, side);

}

double	wall_dist(t_cub3d *cub3d, double rayAngle)
{
	double	sideDist;

	init_raycaster(cub3d);
	while (cub3d->map->array[cub3d->raycaster->tileY][cub3d->raycaster->tileX] != '1')
	{
		sideDist = hypotenuse_len(cub3d, rayAngle, cub3d->raycaster->startX, cub3d->raycaster->startY);
		if (sideDist < 0)
		{
			sideDist = -sideDist;
			get_inTile_coordinate(cub3d, cub3d->player->inTileX, cub3d->raycaster->rayAngle, VERTICAL);
		}
		else
			get_inTile_coordinate(cub3d, cub3d->player->inTileY, cub3d->raycaster->rayAngle, HORIZONTAL);
		cub3d->raycaster->wallDist = cub3d->raycaster->wallDist + sideDist;
	}
	return (cub3d->raycaster->wallDist);
}

void	draw_ceiling(t_cub3d *cub3d)
{

}

void	draw_img(t_cub3d *cub3d)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		cub3d->raycaster->rayAngle = cub3d->player->angle + (FOV / 2) - (i * (FOV / WIDTH));
		cub3d->raycaster->wallDist = wall_dist(cub3d, cub3d->raycaster->rayAngle);
		cub3d->raycaster->wallDist = cub3d->raycaster->wallDist / cos(fabs(cub3d->raycaster->rayAngle - cub3d->player->angle));
		cub3d->raycaster->wallStart = -(HEIGHT / cub3d->raycaster->wallDist) / 2 + HEIGHT / 2;
		if (cub3d->raycaster->wallStart < 0)
			cub3d->raycaster->wallStart = 0;
		cub3d->raycaster->wallEnd = (HEIGHT / cub3d->raycaster->wallDist) / 2 + HEIGHT / 2;
		if (cub3d->raycaster->wallEnd >= HEIGHT)
			cub3d->raycaster->wallEnd = HEIGHT - 1;
		i++;
	}
}
