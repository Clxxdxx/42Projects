/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:14:39 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/10 12:01:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	increment_shlvl(t_env **env_list)
{
	t_env	*shlvl_node;
	int		current_level;
	char	*new_level_str;

	shlvl_node = *env_list;
	while (shlvl_node && ft_strcmp(shlvl_node->name_env, "SHLVL") != 0)
		shlvl_node = shlvl_node->next;
	if (shlvl_node)
	{
		current_level = ft_atoi(shlvl_node->val_env);
		free(shlvl_node->val_env);
		new_level_str = ft_itoa(current_level + 1);
		shlvl_node->val_env = new_level_str;
	}
	else
	{
		new_level_str = ft_strdup("1");
		shlvl_node = ft_lstnew_env("SHLVL", new_level_str, 1);
		ft_lstadd_back_env(env_list, shlvl_node);
		free(new_level_str);
	}
}

static int	fill_args(t_token **tokens, char **args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->type == TOKEN_WORD || tokens[i]->type == TOKEN_SIM_QUOTE
			|| tokens[i]->type == TOKEN_DOB_QUOTE)
		{
			args[count] = ft_strdup(tokens[i]->value);
			if (!args[count])
			{
				while (--count >= 0)
					free(args[count]);
				free(args);
				return (-1);
			}
			count++;
		}
		i++;
	}
	args[count] = NULL;
	return (0);
}

char	**tokens_to_args(t_token **tokens)
{
	char	**args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->type == TOKEN_WORD || tokens[i]->type == TOKEN_SIM_QUOTE
			|| tokens[i]->type == TOKEN_DOB_QUOTE)
			count++;
		i++;
	}
	args = calloc(count + 1, sizeof(char *));
	if (!args)
		return (NULL);
	if (fill_args(tokens, args) == -1)
	{
		free(args);
		return (NULL);
	}
	return (args);
}

void	free_tokens_ext(t_token **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
