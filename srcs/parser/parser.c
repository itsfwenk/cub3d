/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:46:29 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 16:03:57 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cub3d_parser(t_cub3d *cub3d, char *map_path)
{
	int	fd;

	if (!is_correct_filename(map_path))
	{
		ft_print_error("Wrong path extension (.cub)");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_print_error("Can't open this .cub file");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	close(fd);
}
