/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:46:29 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 16:28:35 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cub3d_parser(t_cub3d *cub3d, char *mappath)
{
	int	fd;

	if (!is_correct_filename(mappath, ".cub"))
	{
		ft_print_error("Wrong path extension (.cub)");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	fd = open(mappath, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_print_error("Can't open this .cub file \
(Wrong path, or a directory)");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	close(fd);
}
