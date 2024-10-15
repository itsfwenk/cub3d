/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:04:02 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/15 15:12:28 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = init_cub3d();
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			ft_print_error("Please provide a path to a .cub map");
		else
			ft_print_error("Too many arguments");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	cub3d_parser(cub3d, argv[1]);
	init_window(cub3d);
	return (exit_cub3d(cub3d, EXIT_SUCCESS));
}
