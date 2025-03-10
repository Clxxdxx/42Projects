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
                // Intercambiar arr[i] y arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Intercambiar arr[i + 1] y arr[high]
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // Recursivamente ordenar las dos mitades
        quicksort(arr, low, i);
        quicksort(arr, i + 2, high);
    }
}

int get_pivot(t_list *stack_a)
{
    int size = ft_lstsize(stack_a);
    int *values = (int *)malloc(sizeof(int) * size);
    t_list *tmp = stack_a;
    int i = 0;

    // Llenar el array con los valores de stack_a
    while (tmp)
    {
        values[i++] = *(int *)tmp->content;
        tmp = tmp->next;
    }

    // Ordenar el array
    quicksort(values, 0, size - 1);

    // Elegir el pivote como el valor mediano
    int pivot = values[size / 2];

    // Liberar la memoria
    free(values);

    return pivot;
}

int get_percentil(t_list *stack)
{
    int size = ft_lstsize(stack);
    if (size == 0)
        return 0;

    int *arr = malloc(size * sizeof(int));
    if (!arr)
        return 0;

    // Copiar valores en un array
    t_list *temp = stack;
    int i = 0;
    while (temp)
    {
        arr[i] = *(int *)temp->content;
        temp = temp->next;
        i++;
    }

    // Ordenar array (Bubble Sort con while)
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



