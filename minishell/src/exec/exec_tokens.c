/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:00:00 by clalopez          #+#    #+#             */
/*   Updated: 2025/09/23 11:46:40 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	create_new_tokens(t_token **tokens, char **split_tokens)
{
	int	j;

	j = 1;
	while (split_tokens[j])
	{
		tokens[j] = malloc(sizeof(t_token));
		tokens[j]->value = ft_strdup(split_tokens[j]);
		tokens[j]->type = TOKEN_WORD;
		tokens[j]->heredoc_fd = -1;
		j++;
	}
	tokens[j] = NULL;
}

static void	free_split_tokens(char **split_tokens)
{
	int	k;

	k = 0;
	while (split_tokens[k])
		free(split_tokens[k++]);
	free(split_tokens);
}

int	process_expanded_tokens(t_token **tokens, char *expanded)
{
	char	**split_tokens;

	split_tokens = ft_split(expanded, ' ');
	if (!split_tokens)
	{
		free(expanded);
		return (1);
	}
	free(tokens[0]->value);
	tokens[0]->value = ft_strdup(split_tokens[0]);
	create_new_tokens(tokens, split_tokens);
	free_split_tokens(split_tokens);
	free(expanded);
	return (0);
}
