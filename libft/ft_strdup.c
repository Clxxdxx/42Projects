/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:26:41 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/16 15:02:23 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

/*int main()
{
	const char *original = "Hola, mundo!";
	char *copia = ft_strdup(original);

	if (copia == NULL)
	{
		printf("Error al asignar memoria\n");
		return (1);
	}

	printf("Cadena original: %s\n", original);
	printf("Cadena duplicada: %s\n", copia);
}*/
