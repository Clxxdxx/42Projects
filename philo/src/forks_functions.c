/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:17 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/22 14:56:40 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_forks(t_data *data, t_philo *philo)
{
	int	num_philos;
	int	i;

	num_philos = data->num_philos;
	i = 0;
	while (i < num_philos)
	{
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % num_philos];
		i++;
	}
}

void	get_left_fork_first(t_philo *philo)
{
	long	time_now;

	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->data->print_mutex);
	time_now = get_time_in_ms() - philo->data->start_time;
	printf("[%ld]The philo %d has taken the left_fork... 🍴\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->print_mutex);
	time_now = get_time_in_ms() - philo->data->start_time;
	printf("[%ld]The philo %d has taken the right_fork... 🍴\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	get_right_fork_first(t_philo *philo)
{
	long	time_now;

	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->print_mutex);
	time_now = get_time_in_ms() - philo->data->start_time;
	printf("[%ld]The philo %d has taken the right_fork... 🍴\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->data->print_mutex);
	time_now = get_time_in_ms() - philo->data->start_time;
	printf("[%ld]The philo %d has taken the left_fork... 🍴\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	get_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		get_left_fork_first(philo);
	else
		get_right_fork_first(philo);
}

void	drop_forks(t_philo *philo)
{
	long	time;
	long	time_now;

	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("[%ld]The philo %d has dropped the left_fork... 🔽🍴\n", time_now,
		philo->id);
	pthread_mutex_unlock(philo->right_fork);
	printf("[%ld]The philo %d has dropped the right_fork... 🔽🍴\n", time_now,
		philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}
