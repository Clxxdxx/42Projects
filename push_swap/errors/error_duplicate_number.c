/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_duplicate_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:06 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/26 11:58:52 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	has_duplicate(int *values, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
		values[i] = ft_atoi(args[i]);
		i++;
	}
	return (values);
}

int	error_duplicate_number(int argc, char **argv)
{
	char	**args;
	int		*values;
	int		count;

	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	count = 0;
	while (args[count])
		count++;
	values = convert_args_to_int(args, count);
	if (has_duplicate(values, count))
	{
		free(values);
		if (argc == 2)
			free_args(args);
		return (0);
	}
	free(values);
	if (argc == 2)
		free_args(args);
	return (1);
}
