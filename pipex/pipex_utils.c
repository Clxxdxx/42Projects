/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:48:50 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/04 11:11:53 by clalopez         ###   ########.fr       */
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

	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_free_split(args);
		error_exit("Error al hacer split del comando");
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
