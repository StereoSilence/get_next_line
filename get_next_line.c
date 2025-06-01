/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhov <akorzhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:59:42 by akorzhov          #+#    #+#             */
/*   Updated: 2025/06/01 20:54:05 by akorzhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **buffer)
{
	char	*newline_pos;
	char	*line;
	char	*tmp;

	newline_pos = ft_strchr(*buffer, '\n');
	if (newline_pos)
	{
		line = ft_substr(*buffer, 0, newline_pos - *buffer + 1);
		tmp = ft_strdup(newline_pos + 1);
		free(*buffer);
		*buffer = tmp;
		return (line);
	}
	return (NULL);
}

static int	read_and_append(int fd, char **buffer, char *read_buf)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = read(fd, read_buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	read_buf[bytes_read] = '\0';
	if (*buffer)
	{
		tmp = ft_strjoin(*buffer, read_buf);
		free(*buffer);
		*buffer = tmp;
		if (!*buffer)
			return (-2);
	}
	else
	{
		*buffer = ft_strdup(read_buf);
		if (!*buffer)
			return (-2);
	}
	return (1);
}

/*
static char	*handle_eof(char **buffer, char *read_buf)
{
	char	*line;

	line = NULL;
	if (*buffer && **buffer)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
	free(read_buf);
	return (line);
}
*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*read_buf;
	char		*line;
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	while (1)
	{
		if (buffer && *buffer)
		{
			line = extract_line(&buffer);
			if (line)
				return (free(read_buf), line);
		}
		status = read_and_append(fd, &buffer, read_buf);
		//if (status == 0)
		//	return (handle_eof(&buffer, read_buf));
		if (status < 0)
			return (free(buffer), free(read_buf), buffer = NULL, NULL);
	}
}
