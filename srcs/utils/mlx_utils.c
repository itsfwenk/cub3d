/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:52:41 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/14 19:57:19 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_pixel_color(t_img *img, int x, int y, unsigned long color)
{
	char	*dst;

	dst = (img->addr) + (y * WIDTH * BYTES_PER_PX) + x * (BITS_PER_PX / 8);
	*(unsigned int *)dst = (unsigned int)color;
}

void	color_column(t_cub3d *cub3d, int x)
{
	int	y;

	y = 0;
	while (y < cub3d->raycaster->wall_start)
	{
		set_pixel_color(&cub3d->img, x, y, cub3d->map->colors[CEIL]);
		y++;
	}
	while (y < cub3d->raycaster->wall_end)
	{
		y++;
	}
	while (y < HEIGHT)
	{
		set_pixel_color(&cub3d->img, x, y, cub3d->map->colors[CEIL]);
		y++;
	}
}

void	draw_img(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	(void)y;
	while (x < WIDTH)
	{
		cub3d->raycaster->ray_angle = cub3d->player->angle + 45 - x
			* FOV / WIDTH;
		cub3d->raycaster->wall_dist = wall_dist(cub3d,
				cub3d->raycaster->ray_angle);
		x++;
	}
}
