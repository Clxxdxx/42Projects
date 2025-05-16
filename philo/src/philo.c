/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:34 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/16 15:58:01 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;
	int		i;

	init_data(&data);
	parse_args(argc, argv, &data);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.num_philos);
	if (!data.forks)
		return (1);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_mutex_init(&data.forks[i], NULL);
		i++;
	}

	philos = malloc(sizeof(t_philo) * data.num_philos);
	if (!philos)
		return (1);
	i = 0;
	//printf("Init time: %ld\n", data.start_time);
	while (i < data.num_philos)
	{
		//printf("PHILO %d MEALS: %d\n", philos->id, philos->meals_eaten);
		philos[i].id = i;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_time = get_time_in_ms();
		philos[i].data = &data;
		philos[i].left_fork = &data.forks[i];
		philos[i].right_fork = &data.forks[(i + 1) % data.num_philos];
		i++;
	}
	init_time(&data);
	create_thread_each_philo(philos, &data);
	create_thread_monitor(philos);
	wait_thread_finish(philos, &data);
	//monitor_thread(philos->data, philos);
	free_resources(&data, philos);
	mark_sim_finish(philos->data);
	//printf("OK\n");
	return (0);
}


