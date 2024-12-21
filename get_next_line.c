/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:15:06 by mmounsif          #+#    #+#             */
/*   Updated: 2024/12/21 20:50:24 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd)
{
	char	*buf;
	int		bytes_read;
	char	*stash;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	stash = ft_strdup("");
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buf), NULL);
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		line_len;

	line = read_from_file(fd);
	if (!line)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(line), NULL);
	return (line);
}
