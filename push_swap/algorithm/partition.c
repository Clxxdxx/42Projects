/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_duplicate_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/04 15:30:53 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void partition(t_list **stack_a, t_list **stack_b, int *pivots, int parts)
{
    int size = ft_lstsize(*stack_a);
    int i = 0;

    while (i < size)
    {
        int value = *(int *)(*stack_a)->content;
        int j = 0;
        while (j < parts)
        {
            if (value <= pivots[j])
            {
                pb(stack_a, stack_b);
                break;
            }
            j++;
        }
        if (j == parts)
            ra(stack_a);
        i++;
    }
}





