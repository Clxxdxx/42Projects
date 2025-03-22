/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/22 11:52:02 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void quicksort(int *arr, int low, int high)
{
    int pivot, i, j, temp;

    if (low < high)
    {
        pivot = arr[high];
        i = low - 1;

        for (j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        quicksort(arr, low, i);
        quicksort(arr, i + 2, high);
    }
}

int *get_pivots(t_list *stack, int parts)
{
    int size = ft_lstsize(stack);
    int *arr = malloc(sizeof(int) * size);
    int *pivots = malloc(sizeof(int) * parts);
    int i = 0;

    t_list *tmp = stack;
    while (tmp)
    {
        arr[i++] = *(int *)tmp->content;
        tmp = tmp->next;
    }

    quicksort(arr, 0, size - 1);

    for (i = 0; i < parts; i++)
        pivots[i] = arr[(size / parts) * i];

    free(arr);
    return pivots;
}


int get_percentil(t_list *stack)
{
    int size = ft_lstsize(stack);
    if (size == 0)
        return 0;

    int *arr = malloc(size * sizeof(int));
    if (!arr)
        return 0;
    t_list *temp = stack;
    int i = 0;
    while (temp)
    {
        arr[i] = *(int *)temp->content;
        temp = temp->next;
        i++;
    }
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        int j = 0;
        while (j < size - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = 1;
            }
            j++;
        }
    }
    int percentil = arr[size / 2];
    free(arr);
    return percentil;
}

