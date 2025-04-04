/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:07:23 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/04 11:58:42 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


/*int main(void)
{
	char src[] = "Hola, claudio";
	char *dst;
	size_t copied;

	ft_strlcpy(dst, src, 6);

	printf("Cadena : %s\n", dst);
	return (0);
}*/
