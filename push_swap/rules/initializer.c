/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:50:20 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/28 11:28:20 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

t_list	*init_stack_a(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		*value;
	char	**args;
	int		i;

	stack_a = NULL;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	while (args[i] != NULL)
	{
		value = malloc(sizeof(int));
		if (!value)
			return (NULL);
		*value = ft_atoi(args[i]);
		new_node = ft_lstnew(value);
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	if (argc == 2)
		free_args(args);
	return (stack_a);
}
