/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:25:27 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/26 13:23:44 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (1);
	if (show_error(argc, argv) == 0)
		return (write(2, "Error\n", 6), 1);
	stack_a = init_stack_a(argc, argv);
	stack_b = NULL;
	stack_size = ft_lstsize(stack_a);
	if (stack_size == 2 && !is_sorted(stack_a))
		sa(&stack_a);
	else if (stack_size == 3)
		sort_three(&stack_a);
	else if (stack_size > 3 && !is_sorted(stack_a))
		ksort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
