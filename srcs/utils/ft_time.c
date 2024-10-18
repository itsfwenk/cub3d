/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:12:15 by fli               #+#    #+#             */
/*   Updated: 2024/10/18 10:20:50 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

suseconds_t	get_time_seconds(void)
{
	struct timeval	tp;
	suseconds_t		current_time;

	gettimeofday(&tp, NULL);
	current_time = ((tp.tv_sec * 1000000) + tp.tv_usec) / 1000000;
	return (current_time);
}
