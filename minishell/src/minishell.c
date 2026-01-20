/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:25:47 by clalopez          #+#    #+#             */
/*   Updated: 2025/10/10 12:01:25 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

extern volatile sig_atomic_t	g_skip_next_readline;

char	*gen_shell(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (read_input());
}

int	init_msh(t_shell *msh, char **envp)
{
	ft_memset(msh, 0, sizeof(t_shell));
	msh->env = init_env(envp);
	increment_shlvl(&msh->env);
	msh->exit_status = 0;
	msh->cmd_args = NULL;
	msh->count_cmd_args = 0;
	msh->tokens = NULL;
	msh->parser = NULL;
	msh->shell_fd = dup(STDIN_FILENO);
	msh->shell_pid = get_shell_pid();
	if (msh->shell_fd == -1)
	{
		perror("dup");
		return (1);
	}
	return (0);
}

char	*get_input(int argc, char **argv)
{
	char	*input;

	if (g_skip_next_readline)
	{
		g_skip_next_readline = 0;
		return (NULL);
	}
	input = gen_shell(argc, argv);
	if (!input)
	{
		ft_printf("exit\n");
		clear_history();
	}
	return (input);
}

void	process_tokens(t_token **tokens, t_shell *msh)
{
	int	pipe_check;

	heredoc(msh->env, tokens);
	if (!g_skip_next_readline && tokens && tokens[0])
	{
		pipe_check = has_pipes(tokens);
		if (pipe_check == -1)
			return ;
		else if (pipe_check == 1)
			execute_pipes(tokens, msh);
		else
		{
			free_cmd_args(msh);
			msh->cmd_args = tokens_to_args(tokens);
			execute(tokens, msh);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_token	**tokens_ext;
	t_shell	msh;

	if (init_msh(&msh, envp) == 1)
		return (1);
	call_signals();
	while (1)
	{
		input = get_input(argc, argv);
		if (!input)
			break ;
		if (*input)
		{
			tokens_ext = extract_all_tokens(input);
			process_tokens(tokens_ext, &msh);
			free_tokens_ext(tokens_ext);
		}
		free(input);
	}
	free_cmd_args(&msh);
	free_env(msh.env);
	return (0);
}
