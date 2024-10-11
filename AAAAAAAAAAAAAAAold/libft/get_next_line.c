/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-habi <mel-habi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:23:39 by mel-habi          #+#    #+#             */
/*   Updated: 2024/10/09 12:37:37 by mel-habi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_stashes(char *full_stash, char *stash)
{
	char	*tmp;

	tmp = full_stash;
	full_stash = ft_strjoin(full_stash, stash);
	free(tmp);
	return (full_stash);
}

static char	*read_file(char *full_stash, char stash[], int fd)
{
	int	read_bytes;

	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, stash, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(full_stash), NULL);
		stash[read_bytes] = '\0';
		full_stash = join_stashes(full_stash, stash);
		if (!full_stash)
			return (NULL);
	}
	return (full_stash);
}

static char	*get_line(char *full_stash)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!full_stash[0])
		return (NULL);
	while (full_stash[i] && full_stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + (full_stash[i] == '\n') + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (full_stash[i])
	{
		line[i] = full_stash[i];
		i++;
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

static void	clean_stash(char *full_stash, char stash[])
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (full_stash[i] && full_stash[i] != '\n')
		i++;
	if (!full_stash[i])
		return (free(full_stash), ft_bzero(stash, BUFFER_SIZE + 1));
	i++;
	while (full_stash[i + j])
	{
		stash[j] = full_stash[i + j];
		j++;
	}
	stash[j] = '\0';
	free(full_stash);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*full_stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_bzero(stash, BUFFER_SIZE + 1), NULL);
	full_stash = ft_strdup(stash);
	if (!full_stash)
		return (ft_bzero(stash, BUFFER_SIZE + 1), NULL);
	full_stash = read_file(full_stash, stash, fd);
	if (!full_stash)
		return (ft_bzero(stash, BUFFER_SIZE + 1), NULL);
	line = get_line(full_stash);
	if (!line)
		return (free(full_stash), ft_bzero(stash, BUFFER_SIZE + 1), NULL);
	clean_stash(full_stash, stash);
	return (line);
}
