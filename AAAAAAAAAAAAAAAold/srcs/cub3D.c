/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fli <fli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:04:02 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/10 10:33:53 by fli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	main(int argc, char **argv)
// {
// 	return (EXIT_SUCCESS);
// }

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	(void)ac;
	(void)av;
	init_cub3d(&cub3d);
	// draw_fract(&f);
	// mlx_hook(f.win, 17, 0, clean_exit, &f);
	// mlx_key_hook(f.win, key_event, &f);
	// mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(cub3d.connection);
}
