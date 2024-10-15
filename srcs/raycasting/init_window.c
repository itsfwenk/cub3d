/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:39:12 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/15 10:35:20 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_window(t_cub3d *cub3d)
{
	cub3d->connection = mlx_init();
	if (!cub3d->connection)
		exit_cub3d(cub3d, EXIT_FAILURE);
	cub3d->win = mlx_new_window(cub3d->connection, WIDTH, HEIGHT, WIN_NAME);
	if (!cub3d->win)
		exit_cub3d(cub3d, EXIT_FAILURE);
	cub3d->img.img_ptr = mlx_new_image(cub3d->connection, WIDTH, HEIGHT);
	if (!cub3d->img.img_ptr)
		exit_cub3d(cub3d, EXIT_FAILURE);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img_ptr,
			&cub3d->img.bits_per_pixel,
			&cub3d->img.line_len, &cub3d->img.endian);
	init_raycaster(cub3d);
	mlx_loop(cub3d->connection);
}
