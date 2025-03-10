/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:09:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/27 16:44:30 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_b = second;
	ft_printf("sb\n");
}
void ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
