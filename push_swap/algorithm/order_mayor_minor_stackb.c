/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_mayor_minor_stackb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/22 11:54:56 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Función para encontrar el nodo con el valor máximo y su posición
static void find_max_node(t_list *stack_b, int *max_value, int *max_pos)
{
    t_list *temp;
    int pos;

    if (!stack_b)
        return;
    temp = stack_b;
    *max_value = *(int *)temp->content;
    *max_pos = 0;
    pos = 0;
    while (temp)
    {
        if (*(int *)temp->content > *max_value)
        {
            *max_value = *(int *)temp->content;
            *max_pos = pos;
        }
        temp = temp->next;
        pos++;
    }
}

void order_mayor_minor_stackb(t_list **stack_b, t_list **stack_a)
{
    while (*stack_b)
    {
        int max_value, max_pos;
        find_max_node(*stack_b, &max_value, &max_pos);

        if (max_pos < ft_lstsize(*stack_b) / 2)
        {
            while (*(int *)(*stack_b)->content != max_value)
                rb(stack_b);
        }
        else
        {
            while (*(int *)(*stack_b)->content != max_value)
                rrb(stack_b);
        }
        pa(stack_b, stack_a);
    }
}











