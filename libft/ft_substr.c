/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:24:00 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/17 14:10:15 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	str_len;

	str_len = 0;
	i = 0;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (s[str_len])
		str_len++;
	if (start >= str_len)
		return (malloc(1));
	if (substring == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}*/

/*int main()
{
	char *str = "Hola, mundo!";
	char *substr = ft_substr(str, 7, 5);

	printf("Substring: %s\n", substr);

	free(substr);

	return (0);
}*/