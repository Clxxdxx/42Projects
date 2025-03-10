/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:42:32 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/28 12:32:04 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_list **stack_a)
{
	t_list *last;
	t_list *second_last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}

void rrb(t_list **stack_b)
{
	t_list *last;
	t_list *second_last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}