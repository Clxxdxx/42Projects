/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:06:37 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/10/10 11:55:58 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_valid_unset_name(char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (ft_isdigit(name[0]))
		return (0);
	i = 0;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	remove_env_var(t_env **env, char *name)
{
	t_env	*current;
	t_env	*prev;

	if (!env || !*env || !name)
		return ;
	current = *env;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->name_env, name) == 0)
		{
			if (prev == NULL)
				*env = current->next;
			else
				prev->next = current->next;
			free(current->name_env);
			if (current->val_env)
				free(current->val_env);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	ft_unset(t_shell *msh)
{
	int	i;

	if (!msh)
		return ;
	msh->exit_status = 0;
	if (!msh->cmd_args || msh->count_cmd_args <= 1)
		return ;
	i = 1;
	while (i < msh->count_cmd_args && msh->cmd_args[i])
	{
		if (!is_valid_unset_name(msh->cmd_args[i]))
		{
			ft_putstr_fd("unset: `", 2);
			ft_putstr_fd(msh->cmd_args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			msh->exit_status = 1;
		}
		else
		{
			remove_env_var(&msh->env, msh->cmd_args[i]);
		}
		i++;
	}
}
