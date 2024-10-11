/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:41:03 by fli               #+#    #+#             */
/*   Updated: 2024/10/10 10:35:28 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_img(t_cub3d *cub3d)
{
	int	bit_per_px;
	int	line_length;
	int	endian;

	cub3d->img.img_ptr = mlx_new_image(cub3d->connection, WIDTH, HEIGHT);
	if (cub3d->img.img_ptr == NULL)
		clear_gc(cub3d->gc);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img_ptr,
		&cub3d->img.bits_per_pixel, &cub3d->img.line_len, &cub3d->img.endian);
}

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->connection = mlx_init();
	if (cub3d->connection == NULL)
		clear_gc(cub3d->gc);
	cub3d->win = mlx_new_window(cub3d->connection, WIDTH, HEIGHT, "cub3D");
	if (cub3d->win == NULL)
		clear_gc(cub3d->gc);
	create_img(cub3d);
}

// int	main(int ac, char **av)
// {
// 	t_cub3d	cub3d;

// 	init_cub3d(&cub3d);
// 	// draw_fract(&f);
// 	// mlx_hook(f.win, 17, 0, clean_exit, &f);
// 	// mlx_key_hook(f.win, key_event, &f);
// 	// mlx_mouse_hook(f.win, mouse_event, &f);
// 	mlx_loop(cub3d.connection);
// }
