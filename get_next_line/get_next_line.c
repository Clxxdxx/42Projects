/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:39:56 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/31 11:22:33 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_concat(int fd, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	bytes_read;
	char	*temp;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = concat_line(line, buffer, bytes_read);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		if (ft_strchr(temp, '\n'))
			return (temp);
		line = temp;
	}
	return (line);
}

char	*concat_line(char *line, char *buffer, size_t bytes_read)
{
	size_t	i;
	char	*new_line;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			buffer[i + 1] = '\0';
			break ;
		}
		i++;
	}
	new_line = ft_strjoin(line, buffer);
	free(line);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	return (read_and_concat(fd, line));
}
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("prueba", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}
