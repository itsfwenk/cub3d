/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:36:28 by fli               #+#    #+#             */
/*   Updated: 2024/10/10 11:53:53 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_pos(t_cub3d *cub3d)
{
	cub3d->player->px = (TILE_SIZE * cub3d->player->px) + TILE_SIZE / 2;
	cub3d->player->py = (TILE_SIZE * cub3d->player->py) + TILE_SIZE / 2;
}
