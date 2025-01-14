/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:04:42 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/14 13:31:56 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*u_dest;
	unsigned char	*u_src;
	int				i;

	u_dest = dest;
	u_src = src;
	i = 0;
	while (i < n)
	{
		u_dest[i] = u_src[i];
		i++;
	}
	return (u_dest);
}
