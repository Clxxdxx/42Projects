/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_thread_finish.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:41 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/16 12:44:23 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void wait_thread_finish(t_philo *philo, t_data *data)
{
    int i = 0;
    while (i < data->num_philos)
    {
        pthread_join(philo[i].thread, NULL);
        //printf("Id: %d has eat %d times\n", philo[i].id, philo[i].meals_eaten);
        i++;
    }
}

