/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbogad <jbogad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:34:29 by clalopez          #+#    #+#             */
/*   Updated: 2025/09/23 11:17:43 by jbogad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	restore_stdio(int stdin_backup, int stdout_backup)
{
	if (dup2(stdin_backup, STDIN_FILENO) == -1)
		perror("dup2 stdin");
	if (dup2(stdout_backup, STDOUT_FILENO) == -1)
		perror("dup2 stdout");
	close(stdin_backup);
	close(stdout_backup);
}

void	run_command(t_token **tokens, t_shell *msh)
{
	if (first_env_var(tokens, msh) == 1)
		msh->exit_status = 127;
	else
	{
		expand_env_values(msh->env, tokens);
		fill_cmd_args(tokens, msh);
		execute_builtin(tokens, msh);
	}
}
