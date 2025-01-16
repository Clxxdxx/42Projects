/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:04:42 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/16 17:16:43 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*u_dest;
	unsigned char	*u_src;

	if (dest == NULL || src == NULL)
		return (NULL);
	u_dest = (unsigned char *)dest;
	u_src = (unsigned char *)src;
	while (n--)
	{
		*u_dest++ = *u_src++;
	}
	return (dest);
}
