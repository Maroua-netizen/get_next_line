/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:15:06 by mmounsif          #+#    #+#             */
/*   Updated: 2024/12/17 22:00:18 by mmounsif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd)
{
	int		bytes_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (NULL);
		// bytes_read = 1;
		// while (bytes_read)
		// {
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(cup_buffer), NULL);
		// }
	return (cup_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(basin_buffer), NULL);
	basin_buffer = read_from_file(fd);
	if (!basin_buffer)
		return (NULL);
	return (basin_buffer);
}
