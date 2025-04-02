/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/27 14:39:49 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	k_sort1(t_list **stack_a, t_list **stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (*(int *)(*stack_a)->content <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	k_sort2(t_list **stack_a, t_list **stack_b, int length)
{
	int	rb_count;
	int	rrb_count;
	int	stack_b_size;

	while (length - 1 >= 0)
	{
		stack_b_size = ft_lstsize(*stack_b);
		rb_count = count_r(*stack_b, length - 1);
		rrb_count = stack_b_size - rb_count;
		if (rb_count <= rrb_count)
		{
			while (*(int *)(*stack_b)->content != length - 1)
				rb(stack_b);
			pa(stack_b, stack_a);
			length--;
		}
		else
		{
			while (*(int *)(*stack_b)->content != length - 1)
				rrb(stack_b);
			pa(stack_b, stack_a);
			length--;
		}
	}
}

void	ksort(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		*original_values;
	t_list	*current;
	int		i;

	size = ft_lstsize(*stack_a);
	original_values = (int *)malloc(sizeof(int) * size);
	if (!original_values)
		return ;
	current = *stack_a;
	i = 0;
	while (current)
	{
		original_values[i++] = *(int *)current->content;
		current = current->next;
	}
	assign_sorted_index(stack_a, size);
	k_sort1(stack_a, stack_b, size);
	k_sort2(stack_a, stack_b, size);
	free(original_values);
}
