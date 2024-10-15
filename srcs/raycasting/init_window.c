/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:39:12 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/15 15:14:43 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_textures(t_cub3d *cub3d)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	while (i < 4)
	{
		cub3d->textures[i].img_ptr = mlx_xpm_file_to_image(cub3d->connection,
				cub3d->map->textures[i], &width, &height);
		if (!cub3d->textures[i].img_ptr)
		{
			ft_print_error("Cannot load texture");
			exit_cub3d(cub3d, EXIT_FAILURE);
		}
		else if (width != TILE_SIZE || height != TILE_SIZE)
		{
			ft_print_error("Bad texture size");
			exit_cub3d(cub3d, EXIT_FAILURE);
		}
		cub3d->textures[i].addr = mlx_get_data_addr(cub3d->textures[i].img_ptr,
				&cub3d->textures[i].bits_per_pixel,
				&cub3d->textures[i].line_len, &cub3d->textures[i].endian);
		i++;
	}
}

static void	init_render(t_cub3d *cub3d)
{
	init_textures(cub3d);
	init_dir(cub3d);
	init_raycaster(cub3d);
	init_events(cub3d);
	draw_img(cub3d);
	mlx_loop(cub3d->connection);
}

void	init_window(t_cub3d *cub3d)
{
	cub3d->connection = mlx_init();
	if (!cub3d->connection)
	{
		ft_print_error("Cannot init MLX");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	cub3d->win = mlx_new_window(cub3d->connection, WIDTH, HEIGHT, WIN_NAME);
	if (!cub3d->win)
	{
		ft_print_error("Cannot init MLX window");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	cub3d->img.img_ptr = mlx_new_image(cub3d->connection, WIDTH, HEIGHT);
	if (!cub3d->img.img_ptr)
	{
		ft_print_error("Cannot init MLX IMG PTR");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img_ptr,
			&cub3d->img.bits_per_pixel,
			&cub3d->img.line_len, &cub3d->img.endian);
	init_render(cub3d);
}
