/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:15:06 by mmounsif          #+#    #+#             */
/*   Updated: 2024/12/22 00:52:04 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd, char *stash)
{
	char	*buf;
	size_t	bytes_read;
	char	*temp;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), NULL);
		if (bytes_read == 0)
			break ;
		temp = ft_strjoin(stash, buf);
		free(stash);
		stash = temp;
	}
	return (free(buf), stash);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*stash;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_from_file(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	if (!ft_strchr(stash, '\n'))
	{
		line = ft_strdup(stash);
		return (free(stash), stash = NULL, line);
	}
	line = ft_substr(stash, 0, line_len(stash));
	temp = ft_strdup(stash + line_len(stash));
	free(stash);
	stash = temp;
	return (line);
}
