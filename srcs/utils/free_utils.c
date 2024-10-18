/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:11:49 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/18 13:49:57 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	mlx_free(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	if (cub3d->connection)
	{
		if (cub3d->img.img_ptr)
			mlx_destroy_image(cub3d->connection, cub3d->img.img_ptr);
		if (cub3d->win)
			mlx_destroy_window(cub3d->connection, cub3d->win);
		while (i < 4)
		{
			if (cub3d->textures[i].img_ptr)
				mlx_destroy_image(cub3d->connection,
					cub3d->textures[i].img_ptr);
			i++;
		}
		mlx_destroy_display(cub3d->connection);
		free(cub3d->connection);
	}
}

char	**free_str_tab(char	**tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

bool	unexpected_line_error(t_cub3d *cub3d)
{
	ft_print_error("Found unexpected line while parsing the map");
	exit_cub3d(cub3d, EXIT_FAILURE);
	return (false);
}

int	exit_cub3d(t_cub3d *cub3d, int exit_code)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub3d->map->textures[i])
			free(cub3d->map->textures[i]);
		i++;
	}
	if (cub3d->map->array)
		free(cub3d->map->array);
	if (cub3d->p_line)
		free(cub3d->p_line);
	mlx_free(cub3d);
	clear_lines(cub3d->map->lines);
	clear_gc(cub3d->gc);
	exit(exit_code);
	return (exit_code);
}
