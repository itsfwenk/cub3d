/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:19:53 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/19 01:58:44 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_plane(t_cub3d *cub3d)
{
	double		radiant;

	radiant = cub3d->player->angle * PI / 180.0f;
	if (cub3d->player->angle == 0 || cub3d->player->angle == 180)
	{
		cub3d->raycaster->plane_x = 0.66f * sin(radiant);
		cub3d->raycaster->plane_y = -0.66f * cos(radiant);
	}
	else if (cub3d->player->angle == 90 || cub3d->player->angle == 270)
	{
		cub3d->raycaster->plane_x = -0.66f * sin(radiant);
		cub3d->raycaster->plane_y = 0.66f * cos(radiant);
	}
}

void	init_dir(t_cub3d *cub3d)
{
	if (cub3d->player->angle == 0)
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
	}
	else if (cub3d->player->angle == 90)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
	}
	else if (cub3d->player->angle == 180)
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
	}
	else if (cub3d->player->angle == 270)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
	}
	init_plane(cub3d);
}
