/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:37:24 by bramalho          #+#    #+#             */
/*   Updated: 2025/11/13 15:13:18 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[fd][0])
		line = ft_strjoin_free(line, buffer[fd]);
	while (!ft_strchr_gnl(line, '\n'))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[fd][bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer[fd]);
		if (!line)
			return (NULL);
	}
	if (!line || !line[0])
		return (free(line), NULL);
	new_buffer(buffer[fd]);
	return (line);
}
