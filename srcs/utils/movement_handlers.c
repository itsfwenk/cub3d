/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:03:12 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 21:08:12 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	x_movement(t_map *map, char **array, t_player *player,
	t_movement movement)
{
	if (movement == RIGHT)
	{
		if ((int)(player->x + player->dir_y * MOVEMENT_FORCE) < (int)map->width
			&& array[(int)player->y][(int)(player->x + player->dir_y
			* MOVEMENT_FORCE)] != WALL)
			player->x += player->dir_y * MOVEMENT_FORCE;
		if ((int)(player->y - player->dir_x * MOVEMENT_FORCE) >= 0
			&& array[(int)(player->y - player->dir_x
			* MOVEMENT_FORCE)][(int)player->x] != WALL)
			player->y -= player->dir_x * MOVEMENT_FORCE;
	}
	else
	{
		if ((int)(player->x - player->dir_y * MOVEMENT_FORCE) >= 0
			&& array[(int)player->y][(int)(player->x - player->dir_y
			* MOVEMENT_FORCE)] != WALL)
			player->x -= player->dir_y * MOVEMENT_FORCE;
		if ((int)(player->y + player->dir_x * MOVEMENT_FORCE) < (int)map->height
			&& array[(int)(player->y + player->dir_x
			* MOVEMENT_FORCE)][(int)player->x] != WALL)
			player->y += player->dir_x * MOVEMENT_FORCE;
	}
	return ;
}

void	y_movement(t_map *map, char **array, t_player *player,
	t_movement movement)
{
	if (movement == UP)
	{
		if ((int)(player->x - player->dir_x * MOVEMENT_FORCE) >= 0
			&& array[(int)player->y][(int)(player->x - player->dir_x
			* MOVEMENT_FORCE)] != WALL)
			player->x -= player->dir_x * MOVEMENT_FORCE;
		if ((int)(player->y + player->dir_y * MOVEMENT_FORCE) >= 0
			&& array[(int)(player->y + player->dir_y
			* MOVEMENT_FORCE)][(int)player->x] != WALL)
			player->y -= player->dir_y * MOVEMENT_FORCE;
	}
	else
	{
		if ((int)(player->x + player->dir_x * MOVEMENT_FORCE) < (int)map->width
			&& array[(int)player->y][(int)(player->x + player->dir_x
			* MOVEMENT_FORCE)] != WALL)
			player->x += player->dir_x * MOVEMENT_FORCE;
		if ((int)(player->y + player->dir_y * MOVEMENT_FORCE) < (int)map->height
			&& array[(int)(player->y - player->dir_y
			* MOVEMENT_FORCE)][(int)player->x] != WALL)
			player->y += player->dir_y * MOVEMENT_FORCE;
	}
	return ;
}

void	camera_movement(t_player *player, t_movement movement)
{
	int		coeff;
	double	old_dir_x;

	coeff = -1;
	if (movement == C_LEFT)
		coeff = 1;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(coeff * ROTATE_FORCE)
		- player->dir_y * sin(coeff * ROTATE_FORCE);
	player->dir_y = old_dir_x * sin(coeff * ROTATE_FORCE)
		+ player->dir_y * cos(coeff * ROTATE_FORCE);
	return ;
}
