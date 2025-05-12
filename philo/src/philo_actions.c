/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:02:23 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/12 15:15:44 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sleep_philo(t_philo *philo)
{
	printf("\033[34mPhilo %d is sleeping...\033[0m\n", philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}

void	think_philo(t_philo *philo)
{
	printf("\033[36mPhilo %d is thinking...\033[0m\n", philo->id);
	usleep(1000);
}

void	eat_philo(t_philo *philo)
{
	philo->last_meal_time = get_time_in_ms();
	printf("\033[31mPhilo %d is eating\033[0m\n", philo->id);
	sleep_philo(philo);
	philo->meals_eaten = philo->meals_eaten++;
}
