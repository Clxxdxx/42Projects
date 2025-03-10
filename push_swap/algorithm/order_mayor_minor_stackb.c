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
    int max_value, max_pos;
    int size_b;

    size_b = ft_lstsize(*stack_b);
    if (size_b == 0)
        return;

    while (*stack_b)
    {
        find_max_node(*stack_b, &max_value, &max_pos);
        if (max_pos <= size_b / 2)
        {
            //ft_printf("MM");
            while (*(int *)(*stack_b)->content != max_value)
                rb(stack_b);
        }
        else
        {
            //ft_printf("BB");
            while (*(int *)(*stack_b)->content != max_value)
                rrb(stack_b);
        }
        pa(stack_b, stack_a);
        size_b = ft_lstsize(*stack_b);

        //ft_print_stacks(*stack_a, *stack_b);
    }
}












