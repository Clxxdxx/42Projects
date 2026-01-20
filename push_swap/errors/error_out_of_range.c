/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_of_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:31:01 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/26 11:58:32 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_number(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	error_out_of_range(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
		{
			if (argc == 2)
				free_args(args);
			return (0);
		}
		i++;
	}
	if (argc == 2)
		free_args(args);
	return (1);
}
