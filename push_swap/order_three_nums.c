/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_three_nums.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:01:53 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/22 14:29:18 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest_index(t_list *stack)
{
	int	index;

	index = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > index)
			index = *(int *)stack->content;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_list **stack)
{
	int	biggest;

	if (is_sorted(*stack))
		return ;
	biggest = biggest_index(*stack);
	if (*(int *)(*stack)->content == biggest)
		ra(stack);
	else if (*(int *)(*stack)->next->content == biggest)
		rra(stack);
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
		sa(stack);
}
