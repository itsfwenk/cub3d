/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:04:02 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 15:14:12 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_gc	*gc;
	t_cub3d	*cub3d;

	gc = NULL;
	cub3d = add_gc(&gc, 1, sizeof(t_cub3d));
	cub3d->gc = gc;
	clear_gc(cub3d->gc);
	return (EXIT_SUCCESS);
}
