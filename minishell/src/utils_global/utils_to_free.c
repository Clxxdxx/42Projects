/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:32:49 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/09/23 12:30:36 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_list(t_env **list)
{
	t_env	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		ft_memfree((*list)->name_env);
		ft_memfree((*list)->val_env);
		ft_memfree((*list));
		*list = tmp;
	}
	*list = NULL;
}

void	ft_memfree(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
	ptr = NULL;
}

char	*get_value_of_env(char *fullenv)
{
	char	*equal;

	if (!fullenv)
		return (ft_strdup(""));
	equal = ft_strchr(fullenv, '=');
	if (equal)
		return (ft_strdup(equal + 1));
	return (ft_strdup(""));
}
