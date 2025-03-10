/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:40:11 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/27 17:07:31 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list *first_node;

	if (*stack_b == NULL)
		return;
	first_node = *stack_b;
	*stack_b = (*stack_b)->next;
	first_node->next = *stack_a;
	*stack_a = first_node;
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list *first_node;

	if (*stack_a == NULL)
		return;
	first_node = *stack_a;
	*stack_a = (*stack_a)->next;
	first_node->next = *stack_b;
	*stack_b = first_node;
	ft_printf("pb\n");
}
