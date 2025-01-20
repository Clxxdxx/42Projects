/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:44:05 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/20 15:12:45 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	c &= 255;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}

/*int main()
{
	char palabra[] = "palabra";
	char caracter = 'b';

	char *resultado = ft_strrchr(palabra, caracter);

	if (resultado)
		printf("El caracter '%c' se ha encontrado", caracter);
	else
		printf("El caracter '%c' no se encuentra\n", caracter);

	return (0);
}*/