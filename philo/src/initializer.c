/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:27 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/14 13:03:58 by clalopez         ###   ########.fr       */
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

t_philo	init_philo(int id, t_data *data, pthread_mutex_t *left_fork,
		pthread_mutex_t *right_fork)
{
	t_philo	philo;

	philo.id = id;
	philo.meals_eaten = 0;
	philo.last_meal_time = 0;
	philo.thread = 0;
	philo.left_fork = left_fork;
	philo.right_fork = right_fork;
	philo.data = data;
	return (philo);
}
