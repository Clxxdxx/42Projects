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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = init_stack_a(argc, argv);
	if (!stack_a)
		return (1);

	stack_b = NULL;
	
	//Mostrar stacks inicializados
	ft_printf("----------------------------------------------\nInit a and b:\n");
	ft_print_stacks(stack_a, stack_b);

	//Mostrar dos primeros elementos de stack_a revertidos
	ft_printf("----------------------------------------------\nExec sa:\n");
	sa(&stack_a);
	ft_print_stacks(stack_a, stack_b);
	
	//Pasar y mostrar primer elemento de stack_a a primera posicion de stack_b
	ft_printf("----------------------------------------------\nExec pb:\n");
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ft_print_stacks(stack_a, stack_b);

	//Mostrar dos primeros elementos de stack_b revertidos
	ft_printf("----------------------------------------------\nExec sb:\n");
	sb(&stack_b);
	ft_print_stacks(stack_a, stack_b);
	
	//Mostrar primera y segunda posicion de los stacks revertidos
	ft_printf("----------------------------------------------\nExec ss:\n");
	ss(&stack_a, &stack_b);
	ft_print_stacks(stack_a, stack_b);

	//Pasar y mostrar primer elemento de stack_b a primera posicion de stack_a
	/*ft_printf("----------------------------------------------\nExec pa:\n");
	pa(&stack_b, &stack_a);
	pa(&stack_b, &stack_a);
	pa(&stack_b, &stack_a);
	ft_print_stacks(stack_a, stack_b);*/

	//Desplazar cada elemento una posicion hacia arriba y mostrar
	ft_printf("----------------------------------------------\nExec ra:\n");
	ra(&stack_a);
	ft_print_stacks(stack_a, stack_b);

	//Desplazar cada elemento una posicion hacia arriba y mostrar
	ft_printf("----------------------------------------------\nExec rb:\n");
	rb(&stack_b);
	ft_print_stacks(stack_a, stack_b);

	//ra y rb juntos
	ft_printf("----------------------------------------------\nExec rr:\n");
	rr(&stack_a ,&stack_b);
	ft_print_stacks(stack_a, stack_b);

	//Desplazar cada elemento una posicion hacia abajo y mostrar
	ft_printf("----------------------------------------------\nExec rra:\n");
	rra(&stack_a);
	ft_print_stacks(stack_a, stack_b);

	//Desplazar cada elemento una posicion hacia abajo y mostrar
	ft_printf("----------------------------------------------\nExec rrb:\n");
	rrb(&stack_b);
	ft_print_stacks(stack_a, stack_b);

	//rra y rrb juntos
	ft_printf("----------------------------------------------\nExec rrr:\n");
	rrr(&stack_a ,&stack_b);
	ft_print_stacks(stack_a, stack_b);
	
	ft_lstclear(&stack_a, free);

	return (0);
}


