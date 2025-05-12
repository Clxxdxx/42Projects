/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:17 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/08 11:15:57 by clalopez         ###   ########.fr       */
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

void	get_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("The philo %d has taken the left_fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("The philo %d has taken the right_fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		printf("The philo %d has taken the right_fork\n", philo->id);
		pthread_mutex_lock(philo->left_fork);
		printf("The philo %d has taken the left_fork\n", philo->id);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	printf("The philo %d has dropped the left_fork\n", philo->id);
	pthread_mutex_unlock(philo->right_fork);
	printf("The philo %d has dropped the right_fork\n", philo->id);
}