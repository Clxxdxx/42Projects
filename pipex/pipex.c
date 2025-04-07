/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:43:23 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/07 14:59:35 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_full_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_var;
	char	*full_path;
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
		printf("Path: %s", full_path);
		free(full_path);
		i++;
	}
	printf("P");
	ft_free_split(paths);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1, pid2;
	int		infile, outfile;

	if (argc != 5)
		error_exit("Incorrect number of arguments");
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error_exit("Failure to open infile");
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error_exit("Failure to open outfile");
	if (pipe(fd) < 0)
		error_exit("Failure to create pipe");

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
	close(0);
	close(1);
	close(2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
