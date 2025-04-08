/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:43:23 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/08 15:22:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_cmd_in_paths(char *cmd, char **paths)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (ft_free_split(paths), NULL);
		ft_strcpy(full_path, paths[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (ft_free_split(paths), full_path);
		free(full_path);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

char	*get_full_path(char *cmd, char **envp)
{
	char	*path_var;
	char	**paths;
	int		i;

	path_var = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_var = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	return (search_cmd_in_paths(cmd, paths));
}

char	**reset_envp(char **envp)
{
	int		i;
	char	**new_envp;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp);
		i++;
	}
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (!new_envp[i])
			return (NULL);
		i++;
	}
	new_envp[i++] = ft_strdup("PATH=/usr/bin:/bin");
	new_envp[i] = NULL;
	return (new_envp);
}

void	execute_pipe(char **argv, char **envp, int infile, int outfile)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) < 0)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		child_process(argv[2], infile, fd[1], envp);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		child_process(argv[3], fd[0], outfile, envp);
	}
	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	if (argc != 5)
		error_exit("Incorrect number of arguments");
	envp = reset_envp(envp);
	if (!envp)
		error_exit("Could not set default PATH");
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("Failure to open outfile");
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror(argv[1]);
		execute_pipe(argv, envp, -1, outfile);
		return (1);
	}
	execute_pipe(argv, envp, infile, outfile);
	return (0);
}
