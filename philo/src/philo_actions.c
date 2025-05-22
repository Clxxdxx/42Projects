/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:02:23 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/22 15:52:59 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleep_philo(t_philo *philo)
{
	long	time;
	long	time_now;

	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("\033[34m[%ld]Philo %d is sleeping... 💤\033[0m\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep * 1000);
}

void	think_philo(t_philo *philo)
{
	long	time;
	long	time_now;

	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("\033[36m[%ld]Philo %d is thinking... 🤔\033[0m\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(100);
}

void	eat_philo(t_philo *philo)
{
	long	time;
	long	time_now;

	if (philo->meals_eaten == philo->data->num_times_to_eat)
	{
		pthread_mutex_lock(&philo->data->end_mutex);
		philo->data->simulation_ended = 1;
		pthread_mutex_unlock(&philo->data->end_mutex);
		return ;
	}
	pthread_mutex_lock(&philo->mutex_meal);
	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	philo->last_meal_time = time;
	pthread_mutex_unlock(&philo->mutex_meal);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("\033[33m[%ld]Philo %d is eating... 😋\033[0m\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_eat * 1000);
	philo->meals_eaten++;
}
