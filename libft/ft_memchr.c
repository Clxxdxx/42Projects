/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:41:21 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/15 15:12:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

/*int main()
{
	char str[] = "Hola Mundo";
	char caracter = 'M';

	char *result = ft_memchr(str, caracter, 4);

	if (result)
		printf("Caracter encontrado: '%c' en la posicion %ld\n", *result, result
			- str);
	else
		printf("Caracter no encontrado\n");

	return (0);
}*/