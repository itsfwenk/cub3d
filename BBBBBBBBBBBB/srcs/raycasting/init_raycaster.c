/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:37:15 by fli               #+#    #+#             */
/*   Updated: 2024/10/12 16:40:01 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_dir(t_cub3d *cub3d)
{
	if (cub3d->player->angle == 0)
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
	}
	if (cub3d->player->angle ==  90)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
	}
	if (cub3d->player->angle ==  180)
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
	}
	if (cub3d->player->angle ==  270)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
	}
}

// void	init_tileXY(t_cub3d *cub3d, double rayAngle) // gives first tile to check if wall
// {
// 	if (cub3d->raycaster->wallDist < 0)
// 	{
// 		if (cos(rayAngle) > 0)
// 			cub3d->raycaster->tileX++;
// 		else if (cos(rayAngle) < 0)
// 			cub3d->raycaster->tileX--;
// 		cub3d->raycaster->wallDist = -cub3d->raycaster->wallDist;
// 	}
// 	else if (cub3d->raycaster->wallDist > 0)
// 	{
// 		if (sin(rayAngle) > 0)
// 			cub3d->raycaster->tileY--;
// 		else if (sin(rayAngle) < 0)
// 			cub3d->raycaster->tileY++;
// 	}
// }

void	init_raycaster(t_cub3d *cub3d)
{
	cub3d->raycaster->tileX = cub3d->player->x;
	cub3d->raycaster->tileY = cub3d->player->y;
	cub3d->raycaster->startX = cub3d->player->inTileX;
	cub3d->raycaster->startY = cub3d->player->inTileY;
	cub3d->raycaster->wallDist = hypotenuse_len(cub3d,
		cub3d->raycaster->rayAngle, cub3d->player->inTileX,
		cub3d->player->inTileY);
	if (cub3d->raycaster->wallDist < 0)
	{
		cub3d->raycaster->wallDist = -cub3d->raycaster->wallDist;
		get_inTile_coordinate(cub3d, cub3d->player->inTileX, cub3d->raycaster->rayAngle, VERTICAL);
	}
	else
		get_inTile_coordinate(cub3d, cub3d->player->inTileY, cub3d->raycaster->rayAngle, HORIZONTAL);
}
