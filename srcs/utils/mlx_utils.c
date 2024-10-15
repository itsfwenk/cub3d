/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:52:41 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/15 15:31:18 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_pixel_color(t_img *img, int x, int y, unsigned long color)
{
	char	*dst;

	dst = (img->addr) + (y * img->line_len) + x * (img->bits_per_pixel / 8);
	*(unsigned int *)dst = (unsigned int)color;
}

unsigned int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = (img->addr) + (y * img->line_len) + x * (img->bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

void	draw_wall(t_cub3d *cub3d, int px_y)
{
	double			text_x;
	double			text_y;
	unsigned int	px_color;

	if (cub3d->raycaster->tile_face == WEST
		|| cub3d->raycaster->tile_face == EAST)
		text_x = cub3d->raycaster->start_y;
	else
		text_x = cub3d->raycaster->start_x;
	text_x = text_x / cub3d->raycaster->wall_dist;
	text_y = (double) px_y / cub3d->raycaster->wall_dist;
	px_color = get_pixel_color(&cub3d->textures[cub3d->raycaster->tile_face],
			text_x, text_y);
	set_pixel_color(&cub3d->img, text_x, text_y, px_color);
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
		draw_wall(cub3d, y);
		y++;
	}
	while (y < HEIGHT)
	{
		set_pixel_color(&cub3d->img, x, y, cub3d->map->colors[FLOOR]);
		y++;
	}
}

void	draw_img(t_cub3d *cub3d)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		cub3d->raycaster->ray_angle = cub3d->player->angle + 45 - x
			* FOV / WIDTH;
		cub3d->raycaster->wall_dist = wall_dist(cub3d,
				cub3d->raycaster->ray_angle)
			* cos(fabs(cub3d->raycaster->ray_angle - cub3d->player->angle));
		cub3d->raycaster->wall_start = -(HEIGHT
				/ cub3d->raycaster->wall_dist) / 2 + HEIGHT / 2;
		if (cub3d->raycaster->wall_start < 0)
			cub3d->raycaster->wall_start = 0;
		cub3d->raycaster->wall_end = (HEIGHT / cub3d->raycaster->wall_dist)
			/ 2 + HEIGHT / 2;
		if (cub3d->raycaster->wall_end >= HEIGHT)
			cub3d->raycaster->wall_end = HEIGHT - 1;
		color_column(cub3d, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->connection, cub3d->win,
		cub3d->img.img_ptr, 0, 0);
}
