/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:02:23 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/15 11:11:00 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleep_philo(t_philo *philo)
{
	long	time;
	long	time_now;

	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	printf("\033[34m[%ld]Philo %d is sleeping...\033[0m\n", time_now,
		philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}

void	think_philo(t_philo *philo)
{
	long	time;
	long	time_now;

	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	printf("\033[36m[%ld]Philo %d is thinking...\033[0m\n", time_now,
		philo->id);
	usleep(1000);
}

void	eat_philo(t_philo *philo)
{
	long	time;
	long	time_now;

	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	philo->last_meal_time = time_now;
	printf("\033[33m[%ld]Philo %d is eating\033[0m\n", time_now, philo->id);
	sleep_philo(philo);
	philo->meals_eaten++;
}
