/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:03:12 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/19 03:15:50 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	toogle_has_moved(bool *has_moved)
{
	*has_moved = true;
	return (true);
}

void	x_movement(t_cub3d *cub3d, char **array, t_player *player,
	t_movement movement)
{
	bool	has_moved;

	has_moved = false;
	if (movement == LEFT)
	{
		if (array[(int)player->y][(int)(player->x - player->dir_y
			* MOVEMENT_FORCE)] != WALL && toogle_has_moved(&has_moved))
			player->x -= player->dir_y * MOVEMENT_FORCE;
		if (array[(int)(player->y - player->dir_x
				* MOVEMENT_FORCE)][(int)(player->x)] != WALL
				&& toogle_has_moved(&has_moved))
			player->y -= player->dir_x * MOVEMENT_FORCE;
	}
	else if (movement == RIGHT)
	{
		if (array[(int)player->y][(int)(player->x + player->dir_y
			* MOVEMENT_FORCE)] != WALL && toogle_has_moved(&has_moved))
			player->x += player->dir_y * MOVEMENT_FORCE;
		if (array[(int)(player->y + player->dir_x
				* MOVEMENT_FORCE)][(int)(player->x)] != WALL
				&& toogle_has_moved(&has_moved))
			player->y += player->dir_x * MOVEMENT_FORCE;
	}
	if (has_moved)
		draw_img(cub3d);
}

void	y_movement(t_cub3d *cub3d, char **array, t_player *player,
	t_movement movement)
{
	bool	has_moved;

	has_moved = false;
	if (movement == DOWN)
	{
		if (array[(int)player->y][(int)(player->x - player->dir_x
			* MOVEMENT_FORCE)] != WALL && toogle_has_moved(&has_moved))
			player->x -= player->dir_x * MOVEMENT_FORCE;
		if (array[(int)((player->y + player->dir_y
					* MOVEMENT_FORCE))][(int)(player->x)] != WALL
					&& toogle_has_moved(&has_moved))
			player->y += player->dir_y * MOVEMENT_FORCE;
	}
	else if (movement == UP)
	{
		if (array[(int)player->y][(int)(player->x + player->dir_x
			* MOVEMENT_FORCE)] != WALL && toogle_has_moved(&has_moved))
			player->x += player->dir_x * MOVEMENT_FORCE;
		if (array[(int)(player->y - player->dir_y
				* MOVEMENT_FORCE)][(int)(player->x)] != WALL
				&& toogle_has_moved(&has_moved))
			player->y -= player->dir_y * MOVEMENT_FORCE;
	}
	if (has_moved)
		draw_img(cub3d);
}

void	camera_movement(t_cub3d *cub3d, t_player *player,
	t_raycaster *raycaster, t_movement movement)
{
	int		coeff;
	double	old_dir_x;
	double	old_plane_y;

	coeff = 1;
	if (movement == C_RIGHT)
		coeff = -1;
	old_dir_x = player->dir_x;
	old_plane_y = raycaster->plane_y;
	player->dir_x = player->dir_x * cos(coeff * ROTATE_FORCE)
		- player->dir_y * sin(coeff * ROTATE_FORCE);
	player->dir_y = old_dir_x * sin(coeff * ROTATE_FORCE)
		+ player->dir_y * cos(coeff * ROTATE_FORCE);
	raycaster->plane_y = raycaster->plane_y * cos(coeff * ROTATE_FORCE)
		- raycaster->plane_x * sin(coeff * ROTATE_FORCE);
	raycaster->plane_x = old_plane_y * sin(coeff * ROTATE_FORCE)
		+ raycaster->plane_x * cos(coeff * ROTATE_FORCE);
	draw_img(cub3d);
	return ;
}
