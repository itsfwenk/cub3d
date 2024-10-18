/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:52:41 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/18 18:17:57 by fli              ###   ########.fr       */
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

void	draw_wall(t_cub3d *cub3d, int px_x, int px_y, int first_wall_y)
{
	double			step;
	double			text_pos;
	double			wall_x;
	unsigned int	px_color;

	if (cub3d->raycaster->side == 0)
		wall_x = cub3d->player->y
			+ cub3d->raycaster->perp_wall_dist * cub3d->raycaster->ray_dir_y;
	else
		wall_x = cub3d->player->x + cub3d->raycaster->perp_wall_dist
			* cub3d->raycaster->ray_dir_x;
	wall_x -= floor(wall_x);
	cub3d->raycaster->tex_x = (int)(wall_x * (double)TILE_SIZE);
	if (cub3d->raycaster->side == 0 && cub3d->raycaster->ray_dir_x > 0)
		cub3d->raycaster->tex_x = TILE_SIZE - cub3d->raycaster->tex_x - 1;
	if (cub3d->raycaster->side == 1 && cub3d->raycaster->ray_dir_y < 0)
		cub3d->raycaster->tex_x = TILE_SIZE - cub3d->raycaster->tex_x - 1;
	step = (px_y - first_wall_y) * TILE_SIZE / cub3d->raycaster->line_height;
	text_pos = (cub3d->raycaster->wall_start - HEIGHT / 2
			+ cub3d->raycaster->line_height / 2) * step * !px_x + step * !!px_x;
	cub3d->raycaster->tex_y = (int)text_pos & (TILE_SIZE - 1);
	px_color = get_pixel_color(&cub3d->textures[cub3d->raycaster->tile_face],
			cub3d->raycaster->tex_x, cub3d->raycaster->tex_y);
	set_pixel_color(&cub3d->img, px_x, px_y, px_color);
}

void	color_column(t_cub3d *cub3d, int x)
{
	int	y;
	int	first_wall_y;

	y = 0;
	while (y < cub3d->raycaster->wall_start)
	{
		set_pixel_color(&cub3d->img, x, y, cub3d->map->colors[CEIL]);
		y++;
	}
	first_wall_y = y;
	while (y < cub3d->raycaster->wall_end)
	{
		draw_wall(cub3d, x, y, first_wall_y);
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
	t_raycaster	*rc;

	rc = cub3d->raycaster;
	rc->wd_x = 0;
	rc->wd_y = 0;
	while (rc->wd_x < WIDTH)
	{
		init_raycaster(cub3d);
		raycaster(cub3d, rc->ray_dir_x, rc->ray_dir_y);
		calc_perp_dist(cub3d);
		rc->line_height = (int)(HEIGHT / rc->perp_wall_dist);
		rc->wall_start = -rc->line_height / 2 + HEIGHT / 2;
		if (rc->wall_start < 0)
			rc->wall_start = 0;
		rc->wall_end = rc->line_height / 2 + HEIGHT / 2;
		if (rc->wall_end >= HEIGHT)
			rc->wall_end = HEIGHT - 1;
		color_column(cub3d, rc->wd_x);
		rc->wd_x++;
	}
	mlx_put_image_to_window(cub3d->connection, cub3d->win,
		cub3d->img.img_ptr, 0, 0);
	cub3d->timedata->old_time = cub3d->timedata->time;
	cub3d->timedata->time = get_time_seconds();
}
