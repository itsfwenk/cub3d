/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:05:17 by fli               #+#    #+#             */
/*   Updated: 2024/10/11 19:18:31 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_dir(t_cub3d *cub3d)
{
	if (cub3d->player->angle == 0)
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
	}
	if (cub3d->player->angle ==  PI / 2)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
	}
	if (cub3d->player->angle ==  PI)
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
	}
	if (cub3d->player->angle ==  3 * PI / 2)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
	}
}

// position = position in the current map cell
// angle = angle from 0 = rayAngle => to know which direction player is facing
// => gives opposite or adjacent length
double	side_dist(double position, double angle, t_side side)
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

double	hypotenuse_len(double position, double angle)
{
	double	vertHypo;
	double	horizHypo;
	double	normAngle;

	normAngle = normalize_angle(angle);
	vertHypo = side_dist(position, angle, VERTICAL) / sin(normAngle);
	horizHypo = side_dist(position, angle, HORIZONTAL) / cos(normAngle);
}

void	draw_img(t_cub3d *cub3d)
{
	int		i;
	double	rayAngle;
	double	distVert;
	double	distHoriz;
	double	distToSide;
	int		xMap;
	int		yMap;


	while (i < WIDTH)
	{
		rayAngle = cub3d->player->angle + (FOV / 2) - (i * (FOV / WIDTH));
		distVert = side_dist(cub3d->player->inTileX, rayAngle, VERTICAL);
		distHoriz = side_dist(cub3d->player->inTileY, rayAngle, HORIZONTAL);

		i++;
	}
}
