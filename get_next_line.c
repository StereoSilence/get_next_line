/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:59:42 by akorzhov          #+#    #+#             */
/*   Updated: 2025/05/27 17:37:10 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*newline_pos;
	ssize_t		bytes_read;
	char		*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(buffer);
		leftover = ft_strdup(newline_pos + 1);
		free(buffer);
		buffer = leftover;
	}
	else
	{
		line = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
