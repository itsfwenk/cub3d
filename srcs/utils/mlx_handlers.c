/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:52 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/15 10:59:16 by mel-habi         ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}

static int	handle_mouse(int key, t_cub3d *cub3d)
{
	(void)key;
	(void)cub3d;
	return (EXIT_SUCCESS);
}

void	init_events(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, KeyPress, KeyPressMask,
		handle_key, cub3d);
	mlx_hook(cub3d->win, ButtonPress, ButtonPressMask,
		handle_mouse, cub3d);
	mlx_hook(cub3d->win, DestroyNotify, StructureNotifyMask,
		handle_close, cub3d);
}
