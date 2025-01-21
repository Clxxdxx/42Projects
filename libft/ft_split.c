/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:18:30 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/21 17:06:47 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count + 1);
}

static char	*get_word(char const *s, char c, size_t *i)
{
	size_t	start;
	size_t	len;
	char	*word;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] != '\0' && s[*i] != c)
		(*i)++;
	len = *i - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	len = 0;
	while (len < (*i - start))
	{
		word[len] = s[start + len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

static char	**fill_result(char const *s, char c, size_t num_words)
{
	char	**result;
	size_t	i;
	size_t	j;

	result = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < num_words)
	{
		result[j] = get_word(s, c, &i);
		if (!result[j])
		{
			free_array(result);
			return (NULL);
		}
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	if (c == '\0')
	{
		result = (char **)malloc(2 * sizeof(char *));
		if (!result)
			return (NULL);
		if (s[0] == '\0')
			result[0] = NULL;
		else
			result[0] = ft_strdup(s);
		result[1] = NULL;
		return (result);
	}
	return (fill_result(s, c, count_words(s, c)));
}

/*int	main(void)
{
	// char *s = "  ";
	// char del = ' ';
	// int result;

	// result = count_words(s, del);

	// printf("Número de palabras: %d\n", result);

	char *s = "  Hola  Cla udio  ";
	char del = ' ';
	int result;

	split_words(s, del);
	return (0);
}*/