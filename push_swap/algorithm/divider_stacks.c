/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divider_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:13:38 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/04 14:49:20 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*convert_args_to_int(char **args, int count)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * count);
	if (!values)
		return (0);
	i = 0;
	while (i < count)
	{
		values[i] = atoi(args[i]);
		i++;
	}
	return (values);
}

void	order_minor_major(int *values, int count)
{
	int	i;
	int	temp;
	int	swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < count - 1)
		{
			if (values[i] > values[i + 1])
			{
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	*sort_minus_major(int argc, char **argv)
{
	char	**args;
	int		count;
	int		*values;

	count = 0;
	args = argv + 1;
	if (argc > 2)
		count = argc - 1;
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (1);
		count = 0;
		while (args[count])
			count++;
	}
	values = convert_args_to_int(args, count);
	order_minor_major(values, count);
	// free(values);
	return (values);
}

void divider_stacks(int *values, int count)
{
    int stack_count;
    if (count < 4)
        stack_count = count; 
    else
        stack_count = 4; 

    int *stacks[4];
    int stack_sizes[4] = {0};
    int i = 0;
    while (i < 4)
    {
        stacks[i] = malloc(sizeof(int) * count);
        if (!stacks[i])
            return;
        i++;
    }
    int index = 0;
    i = 0;
    while (i < stack_count)
    {
        int j = 0;
        while (j < count / stack_count)
        {
            stacks[i][stack_sizes[i]++] = values[index++];
            j++;
        }
        i++;
    }
    i = 0;
    while (index < count)
    {
        stacks[i][stack_sizes[i]++] = values[index++];
        i++;
        if (i == stack_count) 
            i = 0;
    }
    printf("Stacks:\n");
    i = 0;
    while (i < stack_count)
    {
        printf("Stack %d: ", i + 1);
        int j = 0;
        while (j < stack_sizes[i])
        {
            printf("%d ", stacks[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    i = 0;
    while (i < 4)
    {
        free(stacks[i]);
        i++;
    }
}
