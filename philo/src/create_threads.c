/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:20 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/12 15:11:39 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
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

    return NULL;
}

void thread_each_philo(t_philo *philo, t_data *data)
{
    int i;
    i = 0;

    while (i < data->num_philos)
    {
        pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
        i++;
    }
}

void *monitor_routine(void *arg)
{
    (void)arg;

    while (1)
    {
        printf("Thread monitor executing:\n");
        usleep(10000);
    }
    return NULL;
}



void thread_monitor()
{
    pthread_t monitor;
    pthread_create(&monitor, NULL, monitor_routine, NULL);
}
