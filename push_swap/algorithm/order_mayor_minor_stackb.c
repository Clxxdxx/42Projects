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
        // Encuentra el valor máximo y su posición en stack_b
        find_max_node(*stack_b, &max_value, &max_pos);
        //ft_printf("Max value in B: %d, Max pos: %d\n", max_value, max_pos);

        // Mover el valor máximo a la cima de stack_b
        if (max_pos <= size_b / 2)
        {
            //ft_printf("MM");
            // Rotamos hacia arriba hasta encontrar el valor máximo
            while (*(int *)(*stack_b)->content != max_value)
                rb(stack_b);  // Rotar stack_b hacia arriba
        }
        else
        {
            //ft_printf("BB");
            // Rotamos hacia abajo hasta encontrar el valor máximo
            while (*(int *)(*stack_b)->content != max_value)
                rrb(stack_b);  // Rotar stack_b hacia abajo
        }

        // Mover el máximo de B a A
        pa(stack_b, stack_a);  // Descomenta esta línea
        //ft_printf("Ejecutando pa: movido %d de B a A\n", max_value);

        // Actualizamos el tamaño de stack_b después de mover un elemento
        size_b = ft_lstsize(*stack_b);

        //ft_print_stacks(*stack_a, *stack_b);  // Mostrar el estado de las pilas
    }
}













