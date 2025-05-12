/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:11:43 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/12 15:12:05 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	monithor_thread(t_data *data, t_philo *philo)
{
	long			time_now;
	int				i;

	i = 0;
	while (!simulation_has_ended(philo->data))
	{
		while (i < data->num_philos)
		{
	        time_now = get_time_in_ms();
			if ((time_now - philo[i].last_meal_time) > data->time_to_die)
			{
				printf("\033[31m El philo %d ha muerto\033[0m\n", i);
				mark_sim_finish(data);
			}
            i++;
		}
		if (i == data->num_philos && data->num_times_to_eat > 0)
			mark_sim_finish(data);
	}
}
