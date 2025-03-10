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

void ksort(t_list **stack_a, t_list **stack_b)
{
    int pivot;

    if (ft_lstsize(*stack_a) <= 1)
        return;

    pivot = get_pivot(*stack_a); // Obtén el pivote

    partition(stack_a, stack_b, pivot); // Particiona la pila A en A y B según el pivote

    // Ordenar stack_b de mayor a menor

    // Llama a push_back solo si stack_a no está vacío
    if (*stack_a)
        push_a_to_b(stack_a, stack_b);
    while (*stack_b) // No necesitamos 'next' aquí
    {
        order_mayor_minor_stackb(stack_b, stack_a); // Ordenar stack_b
    }

    // Ahora mueve los elementos de B a A
    while (*stack_b) // Si stack_b no está vacío
    {
        pa(stack_a, stack_b); // Mueve un elemento de B a A
    }
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
