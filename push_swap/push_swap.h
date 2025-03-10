/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:12:04 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/28 12:31:43 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);
t_list *init_stack_a(int argc, char **argv);
void ft_print_stack_a(t_list *lst);
void	ft_print_stack_b(t_list *lst);
void ft_print_stacks(t_list *stack_a, t_list *stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_b, t_list **stack_a);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
int	error_non_integer(int argc, char **argv);
int	error_duplicate_number(int argc, char **argv);
int	error_out_of_range(int argc, char **argv);
int show_error(int argc, char **argv);
void ksort(t_list **stack_a, t_list **stack_b);
void partition(t_list **stack_a, t_list **stack_b, int pivot);
void push_a_to_b(t_list **stack_a, t_list **stack_b);
void push_b_to_a(t_list **stack_b, t_list **stack_a);
int get_pivot(t_list *stack);
void quicksort(int *arr, int left, int right);
int get_percentil(t_list *stack);
void order_mayor_minor_stackb(t_list **stack_b, t_list **stack_a);
void free_args(char **args);

#endif