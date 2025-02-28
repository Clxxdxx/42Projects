/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:11:13 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/28 11:54:42 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack_a(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		ft_printf("%d ", *(int *)current->content);
		current = current->next;
	}
	ft_printf("\n_ \na\n");
}

void	ft_print_stack_b(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		ft_printf("%d ", *(int *)current->content);
		current = current->next;
	}
	ft_printf("\n_ \nb\n");
}

void	ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	while (current_a != NULL || current_b != NULL)
	{
		if (current_a != NULL)
		{
			ft_printf("%d ", *(int *)current_a->content);
			current_a = current_a->next;
		}
		else
			ft_printf("  ");
		if (current_b != NULL)
		{
			ft_printf("%d ", *(int *)current_b->content);
			current_b = current_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_ ");
	ft_printf("_\n");
	ft_printf("a b\n");
}

