/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:44:05 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/17 14:10:58 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*last;

	last = 0;
	while (*s)
	{
		if ((unsigned char)c == *s)
			last = (unsigned char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((unsigned char *)s);
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