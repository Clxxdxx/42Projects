/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:47:14 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/21 15:25:11 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	err_args(int argc, t_data *data)
{
	if (argc == 5)
	{
		if (data->num_philos < 1 || data->time_to_die < 1
			|| data->time_to_eat < 1 || data->time_to_sleep < 1)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	else if (argc == 6)
	{
		if (data->num_philos < 1 || data->time_to_die < 1
			|| data->time_to_eat < 1 || data->time_to_sleep < 1
			|| data->num_times_to_eat < 1)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	err_non_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_str_digit(argv[i]))
		{
			printf("Error\n");
			exit(0);
		}
		i++;
	}
}
