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

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*remainder)
		return (NULL);
	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	
	ft_strlcpy(line, *remainder, i + 1);
	
	if ((*remainder)[i])
	{
		temp = ft_strdup(&(*remainder)[i]);
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		free(*remainder);
		*remainder = NULL;
	}	
	return (line);
}

static char	*read_file(int fd, char **remainder)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	
	while (!ft_strchr(*remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*remainder, buffer);
		free(*remainder);
		*remainder = temp;
		
		if (!*remainder)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (*remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (!remainder)
		remainder = ft_strdup("");
	
	if (!remainder)
		return (NULL);
	
	remainder = read_file(fd, &remainder);
	
	if (!remainder || !remainder[0])
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	
	return (extract_line(&remainder));
}
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int		fd;
	char	*line;
	int i = 0;

	fd = open("prueba", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]%s",i, line);
		i++;
		free(line);
	}

	close(fd);
	return (0);
}
