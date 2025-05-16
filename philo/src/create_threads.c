/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:20 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/16 16:22:58 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(10000);
	while (!simulation_has_ended(philo->data))
	{
		think_philo(philo);
		get_forks(philo);
		eat_philo(philo);
		drop_forks(philo);
		sleep_philo(philo);
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

void	*monitor_routine(void *arg)
{
	(void)arg;
	while (1)
	{
		//printf("Thread monitor executing:\n");
		usleep(10000);
	}
	return (NULL);
}

void *monitor_thread(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data *data = philo[0].data;
	long	time_now;
	int		i;
	long	time;

	while (!simulation_has_ended(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			time_now = get_time_in_ms();
			if ((time_now - philo[i].last_meal_time) > data->time_to_die)
			{

				time = get_time_in_ms();
				time_now = time - philo->data->start_time;
				printf("\033[31m[%ld] THE PHILO %d HAS DIED\033[0m\n",time_now, i);
				mark_sim_finish(data);
				exit(0);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}


void	create_thread_monitor(t_philo *philos)
{
	pthread_t monitor;

	pthread_create(&monitor, NULL, monitor_routine, (void *)philos);
	pthread_detach(monitor);
}

