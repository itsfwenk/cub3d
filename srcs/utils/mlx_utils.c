/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:52:41 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 11:18:31 by fli              ###   ########.fr       */
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

void	draw_wall(t_cub3d *cub3d,int px_x, int px_y)
{
	int			text_x;
	int			text_y;
	double		step;
	double		text_pos;
	double			wall_x;
	double			lineHeight;
	unsigned int	px_color;

	if (cub3d->raycaster->side == 0)
		wall_x = cub3d->player->y + cub3d->raycaster->perp_wall_dist * cub3d->raycaster->ray_dir_y;
	else
		wall_x = cub3d->player->x + cub3d->raycaster->perp_wall_dist * cub3d->raycaster->ray_dir_x;
	wall_x -= floor(wall_x);
	text_x = (int)(wall_x * (double)TILE_SIZE);
	if (cub3d->raycaster->side == 0 && cub3d->raycaster->ray_dir_x > 0)
		text_x = TILE_SIZE - text_x - 1;
	if (cub3d->raycaster->side == 1 && cub3d->raycaster->ray_dir_y < 0)
		text_x = TILE_SIZE - text_x - 1;
	lineHeight = (int)(HEIGHT / cub3d->raycaster->perp_wall_dist);
	step = 1.0 * TILE_SIZE / lineHeight;
	text_pos = (cub3d->raycaster->wall_start - HEIGHT / 2 + lineHeight / 2) * step;
	text_y = (int)text_pos & (TILE_SIZE - 1);
	px_color = get_pixel_color(&cub3d->textures[cub3d->raycaster->tile_face], text_x, text_y);
	set_pixel_color(&cub3d->img, px_x, px_y, px_color);
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
		draw_wall(cub3d, x, y);
		y++;
	}
	while (y < HEIGHT)
	{
		set_pixel_color(&cub3d->img, x, y, cub3d->map->colors[FLOOR]);
		y++;
	}
}

void	init_step_sidedist(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		cub3d->raycaster->step_x = -1;
		cub3d->raycaster->side_dist_x = (cub3d->player->x - (double)cub3d->raycaster->tile_x) * cub3d->raycaster->delta_dist_x;
	}
	else
	{
		cub3d->raycaster->step_x = 1;
		cub3d->raycaster->side_dist_x = ((double)cub3d->raycaster->tile_x + 1.0 - cub3d->player->x) * cub3d->raycaster->delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		cub3d->raycaster->step_y = -1;
		cub3d->raycaster->side_dist_y = (cub3d->player->y - cub3d->raycaster->tile_y) * cub3d->raycaster->delta_dist_y;
	}
	else
	{
		cub3d->raycaster->step_y = 1;
		cub3d->raycaster->side_dist_y = (cub3d->raycaster->tile_y + 1.0 - cub3d->player->y) * cub3d->raycaster->delta_dist_y;
	}
}

void	raycaster(t_cub3d *cub3d, double ray_dir_x, double ray_dir_y)
{
	// int i = 0;
	init_step_sidedist(cub3d, ray_dir_x, ray_dir_y);
	// printf("cub3d->raycaster->side_dist_x = %f cub3d->raycaster->side_dist_y = %f\n", cub3d->raycaster->side_dist_x, cub3d->raycaster->side_dist_y);
	while (cub3d->map->array[cub3d->raycaster->tile_y][cub3d->raycaster->tile_x] != WALL)
	{
		// printf("i = %d\n", i++);
		if (cub3d->raycaster->side_dist_x < cub3d->raycaster->side_dist_y)
		{
			cub3d->raycaster->side_dist_x += cub3d->raycaster->delta_dist_x;
			cub3d->raycaster->tile_x += cub3d->raycaster->step_x;
			cub3d->raycaster->side = 0;
		}
		else
		{
			cub3d->raycaster->side_dist_y += cub3d->raycaster->delta_dist_y;
			cub3d->raycaster->tile_y += cub3d->raycaster->step_y;
			cub3d->raycaster->side = 1;
		}
		// printf (" cub3d->raycaster->side_dist_x = %f cub3d->raycaster->delta_dist_x = %f\n", cub3d->raycaster->side_dist_x, cub3d->raycaster->delta_dist_x);
		// printf (" cub3d->raycaster->side_dist_y = %f cub3d->raycaster->delta_dist_y = %f\n", cub3d->raycaster->side_dist_y, cub3d->raycaster->delta_dist_y);
		// printf("cub3d->raycaster->tile_y = %d cub3d->raycaster->tile_x = %d\n", cub3d->raycaster->tile_y, cub3d->raycaster->tile_x);
		if (cub3d->raycaster->tile_y > (int)cub3d->map->height || cub3d->raycaster->tile_x > (int)cub3d->map->width)
			break;
	}
}

// void	rc_set(t_cub3d *cub3d)
// {
// 	t_raycaster	*rc;
// 	t_player	*player;

// 	player = cub3d->player;
// 	rc = cub3d->raycaster;
// 	rc->camera_x = 2 * (double)rc->wd_x / WIDTH - 1;
// 	rc->ray_dir_x = player->dir_x + rc->plane_x * rc->camera_x;
// 	rc->ray_dir_y = player->dir_y + rc->plane_y * rc->camera_x;
// 	rc->tile_x = (int)player->x;
// 	rc->tile_y = (int)player->y;
// 	if (rc->ray_dir_x == 0)
// 		rc->delta_dist_x = 1e30;
// 	else
// 		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
// 	if (rc->ray_dir_y == 0)
// 		rc->delta_dist_y = 1e30;
// 	else
// 		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
// 	rc->wall_dist = 0;
// 	rc->hit = 0;
// 	rc->tile_face = 0;
// }

// void	side_step(t_cub3d *cub3d)
// {
// 	t_raycaster	*rc;
// 	t_player	*player;

// 	player = cub3d->player;
// 	rc = cub3d->raycaster;
// 	if (rc->ray_dir_x < 0)
// 	{
// 		rc->step_x = -1;
// 		rc->side_dist_x = (player->x - rc->tile_x) * rc->delta_dist_x;
// 	}
// 	else
// 	{
// 		rc->step_x = 1;
// 		rc->side_dist_x = (rc->tile_x + 1.0 - player->x) * rc->delta_dist_x;
// 	}
// 	if (rc->ray_dir_y < 0)
// 	{
// 		rc->step_y = -1;
// 		rc->side_dist_y = (player->y - rc->tile_x) * rc->delta_dist_y;
// 	}
// 	else
// 	{
// 		rc->step_y = 1;
// 		rc->side_dist_y = (rc->tile_x + 1.0 - player->y) * rc->delta_dist_y;
// 	}
// }

// void	check_hit(t_cub3d *cub3d)
// {
// 	t_raycaster	*rc;
// 	t_map		*map;

// 	rc = cub3d->raycaster;
// 	map = cub3d->map;
// 	while (rc->hit == 0)
// 	{
// 		if (rc->side_dist_x < rc->side_dist_y)
// 		{
// 			rc->side_dist_x += rc->delta_dist_x;
// 			rc->tile_x += rc->step_x;
// 			rc->side = 0;
// 		}
// 		else
// 		{
// 			rc->side_dist_y += rc->delta_dist_y;
// 			rc->tile_y += rc->step_y;
// 			rc->side = 1;
// 		}
// 		if (rc->tile_x > (int)map->width || rc->tile_y > (int)map->height)
// 			rc->hit = 1;
// 		else if (map->array[rc->tile_y][rc->tile_x] == '1')
// 			rc->hit = 1;
// 	}
// }

// void	wall_dist(t_cub3d *cub3d)
// {
// 	t_raycaster	*rc;

// 	rc = cub3d->raycaster;
// 	if (rc->side == 0)
// 	{
// 		if (rc->ray_dir_x > 0)
// 			rc->tile_face = EAST;
// 		else
// 			rc->tile_face = WEST;
// 		rc->wall_dist = (rc->side_dist_x - rc->delta_dist_x);
// 	}
// 	else
// 	{
// 		rc->wall_dist = (rc->side_dist_y - rc->delta_dist_y);
// 		if (rc->ray_dir_y > 0)
// 			rc->tile_face = SOUTH;
// 		else
// 			rc->tile_face = NORTH;
// 	}
// }

// void	draw_data(t_cub3d *cub3d)
// {
// 	t_raycaster	*rc;

// 	rc = cub3d->raycaster;
// 	rc->line_height = (int)(HEIGHT / rc->wall_dist);
// 	rc->wall_start = -rc->line_height / 2 + HEIGHT / 2;
// 	if (rc->wall_start < 0)
// 		rc->wall_start = 0;
// 	rc->wall_end = rc->line_height / 2 + HEIGHT / 2;
// 	if (rc->wall_end >= HEIGHT)
// 		rc->wall_end = HEIGHT - 1;
// 	if (rc->side == 0)
// 		rc->wall_x = cub3d->player->y + rc->wall_dist * rc->ray_dir_y;
// 	else
// 		rc->wall_x = cub3d->player->x + rc->wall_dist * rc->ray_dir_x;
// 	rc->wall_x -= floor(rc->wall_x);
// }

// void	tex_data(t_cub3d *cub3d)
// {
// 	t_raycaster	*rc;

// 	rc = cub3d->raycaster;
// 	rc->tex_x = (int)(rc->wall_x * (double)WIDTH);
// 	if ((rc->side == 0 && rc->ray_dir_x > 0)
// 		|| (rc->side == 1 && rc->ray_dir_y < 0))
// 		rc->tex_x = TILE_SIZE - rc->tex_x - 1;
// 	rc->tex_step = (double)TILE_SIZE / rc->line_height;
// 	rc->tex_pos = (rc->wall_start - HEIGHT
// 			/ 2 + rc->line_height / 2) * rc->tex_step;
// 	rc->data = (int *)cub3d->textures[rc->tile_face].addr;
// 	rc->line_size = cub3d->textures[rc->tile_face].line_len / 4;
// }

// static void	cb_put_pixel(t_cub3d *cub3d, int color, float shading)
// {
// 	int	pixel;
// 	int	*buffer;
// 	t_raycaster	*rc;
// 	t_img	*img;

// 	rc = cub3d->raycaster;
// 	img = &cub3d->img;
// 	pixel = (rc->wd_y * (img->line_len / 4)) + (rc->wd_x);
// 	buffer = (int *)img->addr;
// 	color *= shading;
// 	if (buffer[pixel] != color)
// 		buffer[pixel] = color;
// }

// static void	cb_draw_ceilling_floor(t_cub3d *cub3d, int flag)
// {
// 	t_raycaster	*rc;

// 	rc = cub3d->raycaster;
// 	if (flag == 0)
// 	{
// 		while (rc->wd_y < HEIGHT && rc->wd_y < rc->wall_start)
// 		{
// 			cb_put_pixel(cub3d, cub3d->map->colors[CEIL], 1.0f);
// 			rc->wd_y++;
// 		}
// 		return ;
// 	}
// 	while (rc->wd_y < HEIGHT && rc->wd_y > rc->wall_end)
// 	{
// 		cb_put_pixel(cub3d, cub3d->map->colors[FLOOR], 1.0f);
// 		rc->wd_y++;
// 	}
// }

// static void	cb_draw_wall(t_cub3d *cub3d)
// {
// 	int		color;
// 	t_raycaster	*rc;

// 	rc = cub3d->raycaster;

// 	while (rc->wd_y < HEIGHT && rc->wd_y
// 		>= rc->wall_start && rc->wd_y <= rc->wall_end)
// 	{
// 		rc->tex_y = (int)rc->tex_pos % TILE_SIZE;
// 		rc->tex_pos += rc->tex_step;
// 		color = rc->data[(rc->tex_y * rc->line_size + rc->tex_y)];
// 		cb_put_pixel(cub3d, color, 1.0f);
// 		rc->wd_y++;
// 	}
// }

// void	draw_img(t_cub3d *cub3d)
// {
// 	t_raycaster	*rc;

// 	rc = cub3d->raycaster;
// 	rc->wd_x = 0;
// 	rc->wd_y = 0;
// 	while (rc->wd_x < WIDTH)
// 	{
// 		rc_set(cub3d);
// 		side_step(cub3d);
// 		check_hit(cub3d);
// 		wall_dist(cub3d);
// 		draw_data(cub3d);
// 		tex_data(cub3d);
// 		cb_draw_ceilling_floor(cub3d, 0);
// 		cb_draw_wall(cub3d);
// 		cb_draw_ceilling_floor(cub3d, 1);
// 		rc->wd_x++;
// 	}
// }

void	draw_img(t_cub3d *cub3d)
{
	t_raycaster	*rc;

	rc = cub3d->raycaster;
	rc->wd_x = 0;
	rc->wd_y = 0;
	while (rc->wd_x < WIDTH)
	{

		rc->camera_x = 2 * (double)rc->wd_x / (double)WIDTH - 1;
		rc->ray_dir_x = cub3d->player->dir_x + rc->plane_x * rc->camera_x;
		rc->ray_dir_y = cub3d->player->dir_y + rc->plane_y * rc->camera_x;
		rc->tile_x = (int)(cub3d->player->x);
		rc->tile_y = (int)(cub3d->player->y);
		// printf("rc->tile_x = %d rc->tile_y = %d\n", rc->tile_x, rc->tile_y);
		if (rc->ray_dir_x != 0)
			rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
		else
			rc->delta_dist_x = 1e30;
		if (rc->ray_dir_y != 0)
			rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
		else
			rc->delta_dist_y = 1e30;
		raycaster(cub3d, rc->ray_dir_x, rc->ray_dir_y);
		if (rc->side == 0)
		{
			if (rc->ray_dir_x > 0)
				rc->tile_face = EAST;
			else
				rc->tile_face = WEST;
			rc->perp_wall_dist = (rc->side_dist_x - rc->delta_dist_x);
		}
		else
		{
			if (rc->ray_dir_y > 0)
				rc->tile_face = SOUTH;
			else
				rc->tile_face = NORTH;
			rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
		}
		// printf (" rc->side_dist_x = %f rc->delta_dist_x = %f\n", rc->side_dist_x, rc->delta_dist_x);
		// printf("rc->perp_wall_dist = %f\n", rc->perp_wall_dist);
		rc->line_height = (int)(HEIGHT / rc->perp_wall_dist);
		rc->wall_start = -rc->line_height / 2 + HEIGHT / 2;
		if (rc->wall_start < 0)
			rc->wall_start = 0;
		rc->wall_end = rc->line_height / 2 + HEIGHT / 2;
		if (rc->wall_end >= HEIGHT)
			rc->wall_end = HEIGHT - 1;
		// double distance = sqrt(pow(rc->delta_dist_x, 2) + pow(rc->delta_dist_y, 2));
		printf("perp_wall_dist = %f\n", rc->perp_wall_dist);
		// printf("rc->wall_start = %d rc->wall_end = %d\n", rc->wall_start, rc->wall_end);
		color_column(cub3d, rc->wd_x);
		rc->wd_x++;
	}
	// int i = 0;
	// while (cub3d->map->array[i])
	// {
	// 	int j = 0;
	// 	while (cub3d->map->array[i][j])
	// 	{
	// 		printf("%c",cub3d->map->array[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// printf("player x = %f player y = %f\n",cub3d->player->x, cub3d->player->y);
	mlx_put_image_to_window(cub3d->connection, cub3d->win,
		cub3d->img.img_ptr, 0, 0);
}
