/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:47:55 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/08 15:15:51 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

/*int main()
{
	char dest[30] = "Hello, ";
	char *src = "Claudio123456789!";
	size_t size = 16;

	ft_strlcat(dest, src, size);

	printf("Resultao: %s\n", dest);

	return (0);
}*/