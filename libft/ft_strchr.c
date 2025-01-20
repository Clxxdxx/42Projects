/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:11:30 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/20 16:02:49 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

/*int main()
{
	char palabra[] = "palabra";
	char caracter = 'b';

	char *resultado = ft_strchr(palabra, caracter);

	if (resultado)
		printf("El caracter '%c' se ha encontrado", caracter);
	else
		printf("El caracter '%c' no se encuentra\n", caracter);

	return (0);
}*/