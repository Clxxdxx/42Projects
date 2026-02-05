/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:15:45 by clalopez          #+#    #+#             */
/*   Updated: 2026/02/03 15:31:09 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

volatile sig_atomic_t	g_skip_next_readline = 0;

void	run_heredoc_loop(char *to_search, t_env *env_list, t_token *token,
		int write_fd)
{
	char	*her_input;
	char	*expanded;

	her_input = NULL;
	while (1)
	{
		free(her_input);
		her_input = readline("> ");
		if (!her_input)
			msg_ctrld_heredoc(ft_strdup(to_search));
		if (ft_strcmp(her_input, to_search) == 0)
			break ;
		if (!(token->type == TOKEN_SIM_QUOTE || token->type == TOKEN_DOB_QUOTE)
			&& token->type == TOKEN_WORD)
		{
			expanded = expand_all_vars(env_list, her_input);
			free(her_input);
			her_input = expanded;
		}
		write(write_fd, her_input, ft_strlen(her_input));
		write(write_fd, "\n", 1);
	}
	free(her_input);
	close(write_fd);
	exit(0);
}

static int	create_pipe_and_fork(t_heredoc *hdc)
{
	if (pipe(hdc->fd) == -1)
	{
		perror("pipe");
		free(hdc->to_search);
		return (-1);
	}
	hdc->pid = fork();
	if (hdc->pid < 0)
	{
		perror("fork");
		free(hdc->to_search);
		return (-1);
	}
	if (hdc->pid == 0)
	{
		close(hdc->fd[0]);
		signal(SIGINT, SIG_DFL);
		run_heredoc_loop(hdc->to_search, hdc->env_list, hdc->token, hdc->fd[1]);
		exit(0);
	}
	return (0);
}

static void	handle_parent_process(pid_t pid, int fd[2], t_token **tokens, int i)
{
	int	status;

	close(fd[1]);
	exit_heredoc(pid, &status);
	if (!g_skip_next_readline)
	{
		if (i > 0)
			tokens[i - 1]->heredoc_fd = fd[0];
		else
			close(fd[0]);
	}
	else
		close(fd[0]);
}

void	heredoc(t_env *env_list, t_token **tokens)
{
	int			i;
	t_heredoc	hdc;

	i = 0;
	while (tokens && tokens[i])
	{
		if (is_valid_heredoc(tokens, i))
		{
			hdc.to_search = ft_strdup(tokens[i + 1]->value);
			hdc.env_list = env_list;
			hdc.token = tokens[i + 1];
			if (!hdc.to_search || create_pipe_and_fork(&hdc) == -1)
				return ;
			if (hdc.pid > 0)
				handle_parent_process(hdc.pid, hdc.fd, tokens, i);
			free(hdc.to_search);
			i += 2;
			continue ;
		}
		i++;
	}
}
