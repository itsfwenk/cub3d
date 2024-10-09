/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:48:45 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 19:50:56 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	check_color_number(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n' && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	is_correct_filename(char *filepath, char *extension)
{
	char	*ext;

	ext = ft_strrchr(filepath, '.');
	if (!ext || !((ext - 1)[0]))
		return (false);
	return ((ext - 1)[0] != '/' && !ft_strcmp(ext, extension));
}

unsigned long	ft_atoc(char *nptr)
{
	unsigned long	atoc;
	size_t			i;

	if (!check_color_number(nptr))
		return (LONG_MAX);
	atoc = 0;
	i = 0;
	while (nptr[i])
	{
		if ('0' <= nptr[i] && nptr[i] <= '9')
		{
			atoc = 10 * atoc + (nptr[i] - '0');
			if (atoc > 255)
				return (LONG_MAX);
		}
		i++;
	}
	return (atoc);
}
