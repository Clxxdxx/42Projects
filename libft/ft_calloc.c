/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:53:40 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/16 14:25:51 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = malloc(nmemb * size);
	if (str == NULL)
		return (str);
	ft_memset(str, 0, nmemb * size);
	return (str);
}

/*int main()
{
	int *arr;

	arr = (int *)ft_calloc(5, sizeof(int));
	if (arr == NULL)
	{
		printf("Error al asignar memoria\n");
		return (1);
	}

	for (int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[i]);

	free(arr);
	return (0);
}*/