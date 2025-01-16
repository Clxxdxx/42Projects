/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:44:05 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/15 13:02:21 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if ((char)c == *s)
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

	char *resultado = strrchr(palabra, caracter);

	if (resultado)
		printf("El caracter '%c' se ha encontrado", caracter);
	else
		printf("El caracter '%c' no se encuentra\n", caracter);

	return (0);
}*/