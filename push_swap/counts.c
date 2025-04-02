/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:35:32 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/26 12:05:27 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_r(t_list *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && *(int *)stack->content != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}
