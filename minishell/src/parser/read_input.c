/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:45:09 by claudio           #+#    #+#             */
/*   Updated: 2025/10/10 12:00:42 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*read_input(void)
{
	char	*input;
	char	*prompt;
	char	*tmp;
	char	*short_path;

	short_path = get_short_path();
	tmp = ft_strjoin(GREEN_BRIGHT, short_path);
	prompt = ft_strjoin(tmp, RESET);
	free(tmp);
	free(short_path);
	input = readline(prompt);
	free(prompt);
	if (input && *input != '\0')
		add_history(input);
	return (input);
}
