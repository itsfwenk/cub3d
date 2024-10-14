/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:46:29 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/14 18:13:10 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	parse_line(t_cub3d *cub3d, char *line, int fd)
{
	char	**splitted;

	splitted = ft_split(line, SPACE);
	if (!splitted)
		return (free(line), close(fd), exit_cub3d(cub3d, EXIT_FAILURE), false);
	else if (!splitted[0] || !splitted[1] || splitted[2])
		return (free_str_tab(splitted), false);
	if (!ft_strcmp(splitted[0], "EA") && !cub3d->map->textures[EAST])
		return (parse_simple_line(cub3d, splitted, fd, EAST));
	else if (!ft_strcmp(splitted[0], "NO") && !cub3d->map->textures[NORTH])
		return (parse_simple_line(cub3d, splitted, fd, NORTH));
	else if (!ft_strcmp(splitted[0], "WE") && !cub3d->map->textures[WEST])
		return (parse_simple_line(cub3d, splitted, fd, WEST));
	else if (!ft_strcmp(splitted[0], "SO") && !cub3d->map->textures[SOUTH])
		return (parse_simple_line(cub3d, splitted, fd, SOUTH));
	else if (!ft_strcmp(splitted[0], "C")
		&& cub3d->map->colors[CEIL] == LONG_MAX)
		return (parse_color_line(cub3d, splitted, fd, CEIL));
	else if (!ft_strcmp(splitted[0], "F")
		&& cub3d->map->colors[FLOOR] == LONG_MAX)
		return (parse_color_line(cub3d, splitted, fd, FLOOR));
	close(fd);
	free(line);
	free_str_tab(splitted);
	return (unexpected_line_error(cub3d));
}

static void	parse_parameters(t_cub3d *cub3d, int fd)
{
	int		set_param;
	char	*line;

	set_param = 0;
	while (set_param != 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (parse_line(cub3d, line, fd))
			set_param++;
		free(line);
	}
	if (set_param != 6)
	{
		ft_print_error("There are less than 6 valid parameters \
in this file");
		close(fd);
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
}

static void	parse_map(t_cub3d *cub3d, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && !ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		ft_print_error("This map is empty");
		close(fd);
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
	while (line && ft_strcmp(line, "\n"))
	{
		if (!add_line(cub3d->map, line))
		{
			close(fd);
			exit_cub3d(cub3d, EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

static void	parse_end(t_cub3d *cub3d, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			free(line);
			close(fd);
			ft_print_error("Not empty EOF");
			exit_cub3d(cub3d, EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
}

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
	parse_parameters(cub3d, fd);
	parse_map(cub3d, fd);
	parse_end(cub3d, fd);
	close(fd);
	normalize_map(cub3d);
	lines_to_array(cub3d);
	check_map(cub3d);
}
