/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:48:50 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/07 14:09:08 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	child_process(char *cmd, int in, int out, char **envp)
{
	char	**args;
	char	*path;

	if (dup2(in, STDIN_FILENO) == -1)
		error_exit("dup2 in");
	if (dup2(out, STDOUT_FILENO) == -1)
		error_exit("dup2 out");
	if (in != STDIN_FILENO)
		close(in);
	if (out != STDOUT_FILENO)
		close(out);

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_free_split(args);
		error_exit("Failure to make split of command");
	}
	path = get_full_path(args[0], envp);
	if (!path)
	{
		cmd_not_found(args[0]);
		ft_free_split(args);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve");
	ft_free_split(args);
	free(path);
	exit(EXIT_FAILURE);
}

void	cmd_not_found(char *cmd)
{
	write(2, "command not found: ", 20);
	write(2, cmd, strlen(cmd));
	write(2, "\n", 1);
}

void	ft_free_split(char **arr)
{
	int	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
		
	free(arr);
}
