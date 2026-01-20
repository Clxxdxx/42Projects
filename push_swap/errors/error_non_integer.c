/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_non_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:39:40 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/21 11:25:38 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error_non_integer(int argc, char **argv)
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
		if (!is_valid_integer(args[i]))
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
