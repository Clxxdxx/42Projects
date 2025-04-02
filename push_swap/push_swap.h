/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:12:04 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/26 12:47:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

t_list	*init_stack_a(int argc, char **argv);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		error_non_integer(int argc, char **argv);
int		error_duplicate_number(int argc, char **argv);
int		error_out_of_range(int argc, char **argv);
int		show_error(int argc, char **argv);
void	ksort(t_list **stack_a, t_list **stack_b);
void	quicksort(int *arr, int left, int right);
void	free_args(char **args);
void	sort_three(t_list **stack);
int		is_sorted(t_list *stack);
void	k_sort1(t_list **stack_a, t_list **stack_b, int length);
void	k_sort2(t_list **stack_a, t_list **stack_b, int length);
int		count_r(t_list *stack, int index);
int		ft_sqrt(int number);
void	assign_sorted_index(t_list **stack, int size);

#endif