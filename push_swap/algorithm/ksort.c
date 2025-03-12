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

/*void ksort(t_list **stack_a, t_list **stack_b)
{
    int pivot;

    if (ft_lstsize(*stack_a) <= 1)
        return;

    pivot = get_pivot(*stack_a);

    partition(stack_a, stack_b, pivot); 


    if (*stack_a)
        push_a_to_b(stack_a, stack_b);
    while (*stack_b)
    {
        order_mayor_minor_stackb(stack_b, stack_a);
    }
    while (*stack_b) 
    {
        pa(stack_a, stack_b);
    }
}*/

void radix_sort_push_swap(t_list **stack_a, t_list **stack_b)
{
    int max_bits = get_max_bits(*stack_a);
    int size = ft_lstsize(*stack_a);
    int i = 0, j;

    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((*(int *)(*stack_a)->content >> i) & 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            pa(stack_b, stack_a);
        i++;
    }
}

int get_max_bits(t_list *stack)
{
    int max_value = 0;
    int max_bits = 0;
    t_list *tmp = stack;

    // Encontrar el valor máximo en la lista
    while (tmp)
    {
        if (*(int *)tmp->content > max_value)
            max_value = *(int *)tmp->content;
        tmp = tmp->next;
    }

    // Contar cuántos bits son necesarios para representar max_value
    while ((max_value >> max_bits) != 0)
        max_bits++;

    return max_bits;
}


/*void sort_stack_a(t_list **stack_a, t_list **stack_b)
{
    int percentil;

    if (!stack_a || !*stack_a)
        return;

    percentil = get_percentil(*stack_a);

    while (*stack_a)
    {
        if (*(int *)(*stack_a)->content <= percentil)
        {
            pb(stack_a, stack_b);
        }
        else
        {
            ra(stack_a);
        }
    }

    order_mayor_minor_stackb(stack_b, stack_a);
}*/