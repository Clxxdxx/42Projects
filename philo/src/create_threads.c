/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:20 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/22 16:32:32 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	long	now;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(philo->data->time_to_eat * 1000 / 2);
	while (!simulation_has_ended(philo->data))
	{
		now = get_time_in_ms() - philo->data->start_time;
		pthread_mutex_lock(&philo->data->print_mutex);
		pthread_mutex_unlock(&philo->data->print_mutex);
		get_forks(philo);
		eat_philo(philo);
		drop_forks(philo);
		sleep_philo(philo);
		think_philo(philo);
	}
	return (NULL);
}

void	create_thread_each_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		i++;
	}
}

void	dead_philo(long time_now, int i, t_philo *philo, t_data *data)
{
	long	time;

	if ((time_now - philo[i].last_meal_time) > data->time_to_die)
	{
		time = time_now - philo->data->start_time;
		pthread_mutex_lock(&data->print_mutex);
		printf("\033[31m[%ld] THE PHILO %d HAS DIED 😵\033[0m\n", time, i);
		exit(1);
		pthread_mutex_unlock(&data->print_mutex);
		mark_sim_finish(data);
	}
}

void	*monitor_thread(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	long	time_now;
	int		i;

	philo = (t_philo *)arg;
	data = philo[0].data;
	while (!simulation_has_ended(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_lock(&philo[i].mutex_meal);
			time_now = get_time_in_ms();
			dead_philo(time_now, i, philo, data);
			pthread_mutex_unlock(&philo[i].mutex_meal);
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

void	create_thread_monitor(t_philo *philos)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_thread, (void *)philos);
	pthread_detach(monitor);
}
