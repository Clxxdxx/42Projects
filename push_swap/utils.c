/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/27 12:32:32 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_arr(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	if (low < high)
	{
		pivot = arr[high];
		i = low - 1;
		j = low;
		while (j < high)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap_arr(&arr[i], &arr[j]);
			}
			j++;
		}
		swap_arr(&arr[i + 1], &arr[high]);
		quicksort(arr, low, i);
		quicksort(arr, i + 2, high);
	}
}

void	aux_sorted(t_list **stack, int size, int i, int *index_array)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (*(int *)current->content == index_array[i])
			{
				free(current->content);
				current->content = malloc(sizeof(int));
				*(int *)current->content = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	assign_sorted_index(t_list **stack, int size)
{
	t_list	*current;
	int		*index_array;
	int		i;

	index_array = (int *)malloc(sizeof(int) * size);
	if (!index_array)
		return ;
	current = *stack;
	i = 0;
	while (current)
	{
		index_array[i++] = *(int *)current->content;
		current = current->next;
	}
	quicksort(index_array, 0, size - 1);
	aux_sorted(stack, size, i, index_array);
	free(index_array);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}
