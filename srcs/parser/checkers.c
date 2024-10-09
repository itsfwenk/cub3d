/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:48:45 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 16:29:43 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_correct_filename(char *filepath, char *extension)
{
	return (!ft_strcmp(ft_strrchr(filepath, '.'), extension));
}
