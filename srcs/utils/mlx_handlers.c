/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:52 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/19 00:58:00 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	handle_close(t_cub3d *cub3d)
{
	exit_cub3d(cub3d, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static int	handle_key(int key, t_cub3d *cub3d)
{
	if (key == XK_Escape)
		handle_close(cub3d);
	else if (key == XK_A || key == XK_a)
		x_movement(cub3d, cub3d->map->array, cub3d->player, LEFT);
	else if (key == XK_D || key == XK_d)
		x_movement(cub3d, cub3d->map->array, cub3d->player, RIGHT);
	else if (key == XK_W || key == XK_w)
		y_movement(cub3d, cub3d->map->array, cub3d->player, UP);
	else if (key == XK_S || key == XK_s)
		y_movement(cub3d, cub3d->map->array, cub3d->player, DOWN);
	else if (key == XK_Left)
		camera_movement(cub3d, cub3d->player, cub3d->raycaster, C_LEFT);
	else if (key == XK_Right)
		camera_movement(cub3d, cub3d->player, cub3d->raycaster, C_RIGHT);
	return (EXIT_SUCCESS);
}

void	init_events(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, KeyPress, KeyPressMask,
		handle_key, cub3d);
	mlx_hook(cub3d->win, KeyRelease, KeyReleaseMask,
		handle_key, cub3d);
	mlx_hook(cub3d->win, DestroyNotify, StructureNotifyMask,
		handle_close, cub3d);
}
