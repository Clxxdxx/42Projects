/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:04:51 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/10/10 11:56:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_valid_token_type(t_token *token)
{
	return (token->type == TOKEN_WORD || token->type == TOKEN_DOB_QUOTE
		|| token->type == TOKEN_SIM_QUOTE);
}

void	execute(t_token **tokens, t_shell *msh)
{
	int	stdin_backup;
	int	stdout_backup;
	int	status;

	stdin_backup = dup(STDIN_FILENO);
	stdout_backup = dup(STDOUT_FILENO);
	if (!tokens || !tokens[0] || !is_valid_token_type(tokens[0]))
		return ;
	if (tokens[0]->heredoc_fd != -1)
	{
		dup2(tokens[0]->heredoc_fd, STDIN_FILENO);
		close(tokens[0]->heredoc_fd);
	}
	status = set_redirections(tokens, msh, -1);
	if (status != 1)
		msh->exit_status = 1;
	else
		run_command(tokens, msh);
	restore_stdio(stdin_backup, stdout_backup);
}

void	execute_builtin(t_token **tokens, t_shell *msh)
{
	if (ft_strcmp(tokens[0]->value, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(tokens[0]->value, "echo") == 0)
		ft_echo(tokens, msh);
	else if (ft_strcmp(tokens[0]->value, "export") == 0)
		ft_export(msh);
	else if (ft_strcmp(tokens[0]->value, "exit") == 0)
		ft_exit(msh);
	else if (ft_strcmp(tokens[0]->value, "env") == 0)
		ft_env(msh);
	else if (ft_strcmp(tokens[0]->value, "unset") == 0)
		ft_unset(msh);
	else if (ft_strcmp(tokens[0]->value, "cd") == 0)
		ft_cd(msh);
	else
		execute_external_command(tokens, msh);
}
