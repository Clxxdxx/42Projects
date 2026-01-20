/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:00:00 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/10 11:37:55 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	count_tokens(t_token **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

void	fill_cmd_args(t_token **tokens, t_shell *msh)
{
	int		i;
	int		j;
	int		count;

	if (!tokens || !msh)
		return ;
	free_cmd_args(msh);
	count = count_tokens(tokens);
	msh->cmd_args = ft_calloc(count + 1, sizeof(char *));
	msh->count_cmd_args = count;
	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (tokens[i]->type == TOKEN_WORD
			|| tokens[i]->type == TOKEN_SIM_QUOTE
			|| tokens[i]->type == TOKEN_DOB_QUOTE)
			msh->cmd_args[j++] = ft_strdup(tokens[i]->value);
		i++;
	}
}
