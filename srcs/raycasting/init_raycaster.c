/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:19:53 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 18:33:57 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_dir(t_cub3d *cub3d)
{
	float		radiant;

	if (cub3d->player->angle == 0)
	{
		cub3d->player->dir_x = 1;
		cub3d->player->dir_y = 0;
	}
	if (cub3d->player->angle == 90)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = 1;
	}
	if (cub3d->player->angle == 180)
	{
		cub3d->player->dir_x = -1;
		cub3d->player->dir_y = 0;
	}
	if (cub3d->player->angle == 270)
	{
		cub3d->player->dir_x = 0;
		cub3d->player->dir_y = -1;
	}
	radiant = cub3d->player->angle * PI / 180.0f;
	cub3d->raycaster->plane_x = -0.66f * sin(radiant);
	cub3d->raycaster->plane_y = 0.66f * cos(radiant);
}
