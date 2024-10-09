/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:48:45 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 16:46:58 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_correct_filename(char *filepath, char *extension)
{
	char	*ext;

	ext = ft_strrchr(filepath, '.');
	if (!ext || !((ext - 1)[0]))
		return (false);
	return ((ext - 1)[0] != '/' && !ft_strcmp(ext, extension));
}
