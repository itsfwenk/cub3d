/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:57:49 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/17 18:41:41 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// double	adjacent_opposite(double position, double angle, t_side side)
// {
// 	if (side == HORIZONTAL)
// 	{
// 		if (sin(angle) > 0)
// 			return (position);
// 		return (1 - position);
// 	}
// 	if (cos(angle) < 0)
// 		return (position);
// 	return (1 - position);
// }

// double	normalize_angle(double angle)
// {
// 	if (cos(angle) < 0 && sin(angle) > 0)
// 		return (angle - 45);
// 	else if (cos(angle) < 0 && sin(angle) < 0)
// 		return (angle - 90);
// 	else if (cos(angle) > 0 && sin(angle) < 0)
// 		return (angle - 135);
// 	return (angle);
// }

// double	hypotenuse_len(t_cub3d *cub3d, double ray_angle)
// {
// 	double	vert_hypo;
// 	double	hori_hypo;
// 	double	norm_angle;

// 	norm_angle = normalize_angle(ray_angle);
// 	vert_hypo = adjacent_opposite(cub3d->player->in_tile_x, ray_angle,
// 			VERTICAL) / sin(norm_angle);
// 	hori_hypo = adjacent_opposite(cub3d->player->in_tile_y, ray_angle,
// 			HORIZONTAL) / cos(norm_angle);
// 	if (vert_hypo < hori_hypo)
// 		return (-vert_hypo);
// 	return (hori_hypo);
// }
