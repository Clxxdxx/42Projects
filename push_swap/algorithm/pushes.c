/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/22 11:51:54 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push_a_to_b(t_list **stack_a, t_list **stack_b)
{
    if (*stack_a) 
    {
        pb(stack_a, stack_b);
    }
}

void push_b_to_a(t_list **stack_b, t_list **stack_a)
{
    if (*stack_b) 
    {
        pa(stack_b, stack_a);
    }
}