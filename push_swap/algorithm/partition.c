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

void partition(t_list **stack_a, t_list **stack_b, int pivot)
{
    t_list *tmp;

    tmp = *stack_a;
    while (tmp) 
    {
        if (*(int *)tmp->content <= pivot) 
        {
            pb(stack_a, stack_b); 
        } 
        else 
        {
            ra(stack_a);

        }
        tmp = *stack_a;
        tmp = tmp->next;
    }
}




