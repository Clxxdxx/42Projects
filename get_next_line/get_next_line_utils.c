/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:39:58 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/03 11:59:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*u_dest;
	unsigned char	*u_src;

	if (!dest && !src)
		return (NULL);
	u_dest = (unsigned char *)dest;
	u_src = (unsigned char *)src;
	while (n--)
		*u_dest++ = *u_src++;
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;
	size_t			total;
	size_t			i;

	total = nmemb * size;
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < total)
		str[i++] = 0;
	return (str);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	total_length;

	total_length = 0;
	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[total_length])
		total_length++;
	while (s2[j++])
		total_length++;
	str = (char *)malloc(total_length + 1);
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

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
