/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:00:00 by clalopez          #+#    #+#             */
/*   Updated: 2025/09/23 15:34:08 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_cmd_args(t_shell *msh)
{
	int	i;

	if (!msh || !msh->cmd_args)
		return ;
	i = 0;
	while (msh->cmd_args[i])
	{
		free(msh->cmd_args[i]);
		msh->cmd_args[i] = NULL;
		i++;
	}
	free(msh->cmd_args);
	msh->cmd_args = NULL;
	msh->count_cmd_args = 0;
}

static int	handle_special_vars(char *name_var, t_shell *msh)
{
	if (ft_strcmp(name_var, "$$") == 0)
	{
		printf("%d: command not found\n", msh->shell_pid);
		return (1);
	}
	if (ft_strcmp(name_var, "$?") == 0)
	{
		printf("%d: command not found\n", msh->exit_status);
		return (1);
	}
	return (0);
}

static int	check_directory_path(char *expanded)
{
	int	i;

	i = 0;
	while (expanded[i])
	{
		if (expanded[i] == '/')
		{
			printf("minishell: %s: Is a directory\n", expanded);
			return (1);
		}
		i++;
	}
	return (0);
}

int	first_env_var(t_token **tokens, t_shell *msh)
{
	char	*name_var;
	char	*expanded;

	if (!tokens || !tokens[0])
		return (0);
	name_var = tokens[0]->value;
	if (handle_special_vars(name_var, msh))
		return (1);
	if (name_var[0] == '$')
	{
		expanded = expand_all_vars(msh->env, name_var);
		if (!expanded || expanded[0] == '\0')
			return (1);
		if (check_directory_path(expanded))
		{
			free(expanded);
			return (1);
		}
		if (process_expanded_tokens(tokens, expanded))
			return (1);
		return (0);
	}
	return (0);
}
