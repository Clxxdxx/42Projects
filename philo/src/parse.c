/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:31 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/21 12:30:02 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	parse_args(int argc, char **argv, t_data *data)
{
	data->num_philos = convert_to_int(argv[1]);
	data->time_to_die = convert_to_int(argv[2]);
	data->time_to_eat = convert_to_int(argv[3]);
	data->time_to_sleep = convert_to_int(argv[4]);
	if (argc == 6)
		data->num_times_to_eat = convert_to_int(argv[5]);
	else
		data->num_times_to_eat = -1;
}
