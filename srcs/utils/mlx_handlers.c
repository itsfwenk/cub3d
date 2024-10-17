/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:52 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 19:39:39 by mel-habi         ###   ########.fr       */
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
	char		**map;
	t_player	*player;

	map = cub3d->map->array;
	player = cub3d->player;
	if (key == XK_Escape)
		handle_close(cub3d);
	else if (key == XK_A || key == XK_a)
		x_movement(map, player, LEFT);
	else if (key == XK_D || key == XK_d)
		x_movement(map, player, RIGHT);
	else if (key == XK_W || key == XK_w)
		y_movement(map, player, UP);
	else if (key == XK_S || key == XK_s)
		y_movement(map, player, DOWN);
	else if (key == XK_Left)
		camera_movement(map, player, C_LEFT);
	else if (key == XK_Right)
		camera_movement(map, player, C_RIGHT);
	else
		return (EXIT_SUCCESS);
	draw_img(cub3d);
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
