/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:27 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/22 16:14:07 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_data(t_data *data)
{
	data->num_philos = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->num_times_to_eat = 0;
	data->start_time = 0;
	data->simulation_ended = 0;
	data->forks = NULL;
	pthread_mutex_init(&data->end_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
}

void	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philos[i].id = i;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = get_time_in_ms();
		philos[i].data = data;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		pthread_mutex_init(&philos[i].mutex_meal, NULL);
		i++;
	}
}
