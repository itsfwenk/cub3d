/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:46:29 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 19:40:54 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	parse_line(t_cub3d *cub3d, char *line, int fd)
{
	char	**splitted;

	splitted = ft_split(line, ' ');
	if (!splitted)
		return (free(line), close(fd), exit_cub3d(cub3d, EXIT_FAILURE), false);
	else if (splitted[0] && splitted[1] && !splitted[2])
	{
		if (!ft_strcmp(splitted[0], "NO"))
			return (parse_simple_line(cub3d, splitted, fd, NORTH));
		else if (!ft_strcmp(splitted[0], "SO"))
			return (parse_simple_line(cub3d, splitted, fd, SOUTH));
		else if (!ft_strcmp(splitted[0], "WE"))
			return (parse_simple_line(cub3d, splitted, fd, WEST));
		else if (!ft_strcmp(splitted[0], "EA"))
			return (parse_simple_line(cub3d, splitted, fd, EAST));
		else if (!ft_strcmp(splitted[0], "F"))
			return (parse_color_line(cub3d, splitted, fd, FLOOR));
		else if (!ft_strcmp(splitted[0], "C"))
			return (parse_color_line(cub3d, splitted, fd, CEIL));
		else
			return (close(fd), free(line), free_str_tab(splitted),
				unexpected_line_error(cub3d));
	}
	free_str_tab(splitted);
	return (false);
}

static void	check_param_nb(t_cub3d *cub3d, int set_param, int fd)
{
	if (set_param != 6)
	{
		close(fd);
		if (set_param < 6)
			ft_print_error("There are less than 6 valid parameters \
in this file");
		else
			ft_print_error("There are more than 6 valid parameters \
in this file");
		exit_cub3d(cub3d, EXIT_FAILURE);
	}
}

static void	parse_parameters(t_cub3d *cub3d, int fd)
{
	int		set_param;
	char	*line;

	set_param = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (parse_line(cub3d, line, fd))
			set_param++;
		free(line);
	}
	check_param_nb(cub3d, set_param, fd);
}

static void	parse_map(t_cub3d *cub3d, int fd)
{
	(void)cub3d;
	(void)fd;
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
	close(fd);
}
