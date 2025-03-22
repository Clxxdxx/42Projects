/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:25:27 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/22 14:19:05 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ARG="$(shuf -i 1-1000 -n 100 | tr '\n' ' ')"; ./push_swap $ARG | wc -l
// ARG="$(shuf -i 1-1000 -n 100 | tr '\n' ' ')"; ./push_swap $ARG | ./checker_linux $ARG

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
    int stack_size = ft_lstsize(stack_a);
    //ft_print_stacks(stack_a, stack_b);
    if (stack_size == 2 && !is_sorted(stack_a))
		sa(&stack_a);
	else if (stack_size == 3)
		sort_three(&stack_a);
	else if (stack_size > 3 && !is_sorted(stack_a))
		ksort(&stack_a, &stack_b);
    
    //ft_printf("Size: %d\n", stack_size);
    //ksort(&stack_a, &stack_b);
    //radix_sort_push_swap(&stack_a, &stack_b);
    //ft_print_stacks(stack_a, stack_b); 
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);

    return (0);
}

int is_sorted(t_list *stack)
{
    while (stack->next != NULL)
    {
        if (*(int *)stack->content > *(int *)stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}


