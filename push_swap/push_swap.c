/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:25:27 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/28 12:38:08 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
    
    if (argc < 2)
        return (1);
    if (show_error(argc, argv) == 0)
        return (write(2, "Error\n", 6), 1);

    stack_a = init_stack_a(argc, argv);
    stack_b = NULL;

    //ft_print_stacks(stack_a, stack_b);

    ksort(&stack_a, &stack_b);  

    ft_print_stacks(stack_a, stack_b); 
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);

    return (0);
}

