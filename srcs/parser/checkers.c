/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:48:45 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 15:54:08 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_correct_filename(char *filename)
{
	size_t	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			return (!ft_strcmp(&filename[i], ".cub"));
		i++;
	}
	return (false);
}
