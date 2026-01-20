/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_exec_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:10:08 by clalopez          #+#    #+#             */
/*   Updated: 2025/09/23 15:04:52 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	has_redirection(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->type == TOKEN_REDIR_IN
			|| tokens[i]->type == TOKEN_REDIR_OUT
			|| tokens[i]->type == TOKEN_APPEND
			|| tokens[i]->type == TOKEN_HEREDOC)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_command_path(t_token **tokens, t_shell *msh)
{
	char	*cmd_path;

	cmd_path = find_path(tokens[0]->value, msh->env);
	if (!cmd_path)
	{
		ft_printf("minishell: %s: command not found\n", tokens[0]->value);
		msh->exit_status = 127;
		return (NULL);
	}
	return (cmd_path);
}

void	child_process(char *cmd_path, t_token **tokens, t_shell *msh)
{
	char	**envp;
	char	**argv;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (msh->shell_fd != -1 && !has_redirection(tokens))
		dup2(msh->shell_fd, STDIN_FILENO);
	envp = create_env_array(msh->env);
	argv = create_argv_array(tokens);
	execve(cmd_path, argv, envp);
	perror("execve");
	free_arrays(argv, envp);
	exit(127);
}

char	**get_paths(t_env *env)
{
	char	*path_env;
	char	**paths;

	while (env && ft_strcmp(env->name_env, "PATH") != 0)
		env = env->next;
	if (!env)
		return (NULL);
	path_env = env->val_env;
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (paths);
}
