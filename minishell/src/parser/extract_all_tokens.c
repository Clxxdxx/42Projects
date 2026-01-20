/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_all_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:47:31 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/10 11:57:50 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_total_tokens(char *input)
{
	int	ops_tokens;
	int	dob_quotes_tokens;
	int	sim_quotes_tokens;
	int	word_tokens;
	int	total;

	ops_tokens = count_operator_tokens(input);
	dob_quotes_tokens = count_quotes_dob_tokens(input);
	sim_quotes_tokens = count_quotes_sim_tokens(input);
	word_tokens = count_word_token(input);
	total = ops_tokens + dob_quotes_tokens + sim_quotes_tokens + word_tokens;
	return (total);
}

t_token	*get_next_ops_token(char *input, int *i)
{
	t_token	*token;

	token = extract_double_redir_token(input, i);
	if (token != NULL)
		return (token);
	token = extract_single_redir_token(input, i);
	if (token != NULL)
		return (token);
	token = extract_pipe_token(input, i);
	if (token != NULL)
		return (token);
	return (NULL);
}

t_token	*get_next_token(char *input, int *i)
{
	t_token	*token;

	token = get_next_ops_token(input, i);
	if (token != NULL)
		return (token);
	if (input[*i] == '\'')
	{
		token = extract_sim_quote_token(input, i);
		if (token != NULL)
			return (token);
	}
	if (input[*i] == '"')
	{
		token = extract_dob_quote_token(input, i);
		if (token != NULL)
			return (token);
	}
	token = extract_word_token_inline(input, i);
	if (token != NULL)
		return (token);
	(*i)++;
	return (NULL);
}

t_token	**extract_all_tokens(char *input)
{
	t_token	**tokens;
	t_token	*token;
	int		pos;
	int		count;
	int		capacity;

	pos = 0;
	count = 0;
	capacity = count_total_tokens(input);
	tokens = ft_calloc(capacity + 2, sizeof(t_token *));
	if (!tokens)
		return (NULL);
	while (input[pos])
	{
		while (input[pos] == ' ' || input[pos] == '\t')
			pos++;
		if (!input[pos])
			break ;
		token = get_next_token(input, &pos);
		add_or_free_token(token, tokens, &count);
	}
	tokens[count] = NULL;
	return (tokens);
}
