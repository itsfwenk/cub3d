/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:03:12 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/18 18:19:02 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	x_movement(char **array, t_player *player, t_movement movement)
{
	if (movement == LEFT)
	{
		if (array[(int)player->y][(int)(player->x - player->dir_y
			* MOVEMENT_FORCE)] != WALL)
			player->x -= player->dir_y * MOVEMENT_FORCE;
		if (array[(int)(player->y + player->dir_x
				* MOVEMENT_FORCE)][(int)(player->x)] != WALL)
			player->y += (-1) * player->dir_x * MOVEMENT_FORCE;
	}
	else if (movement == RIGHT)
	{
		if (array[(int)player->y][(int)(player->x + player->dir_y
			* MOVEMENT_FORCE)] != WALL)
			player->x += player->dir_y * MOVEMENT_FORCE;
		if (array[(int)(player->y - player->dir_x
				* MOVEMENT_FORCE)][(int)(player->x)] != WALL)
			player->y -= (-1) * player->dir_x * MOVEMENT_FORCE;
	}
	return ;
}

void	y_movement(char **array, t_player *player, t_movement movement)
{
	if (movement == DOWN)
	{
		if (array[(int)player->y][(int)(player->x - player->dir_x
			* MOVEMENT_FORCE)] != WALL)
			player->x -= player->dir_x * MOVEMENT_FORCE;
		if (array[(int)((player->y + player->dir_y
					* MOVEMENT_FORCE))][(int)(player->x)] != WALL)
			player->y += player->dir_y * MOVEMENT_FORCE;
	}
	else if (movement == UP)
	{
		if (array[(int)player->y][(int)(player->x + player->dir_x
			* MOVEMENT_FORCE)] != WALL)
			player->x += player->dir_x * MOVEMENT_FORCE;
		if (array[(int)(player->y - player->dir_y
				* MOVEMENT_FORCE)][(int)(player->x)] != WALL)
			player->y -= player->dir_y * MOVEMENT_FORCE;
	}
	return ;
}

void	camera_movement(t_player *player, t_raycaster *raycaster,
	t_movement movement)
{
	int		coeff;
	double	old_dir_x;
	double	old_plane_y;

	coeff = -1;
	if (movement == C_LEFT)
		coeff = 1;
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
	return ;
}
