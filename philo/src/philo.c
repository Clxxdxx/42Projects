/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:34 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/22 16:24:20 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	one_philo(t_data *data, t_philo *philo)
{
	long	time;
	long	time_now;

	time = get_time_in_ms();
	time_now = time - philo->data->start_time;
	if (data->num_philos == 1)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("\033[31m[%ld] THE PHILO 0 HAS DIED 😵\033[0m\n", time_now);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	return (0);
}

int	run_simulation(t_data *data)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!philos)
		return (1);
	init_time(data);
	init_philos(data, philos);
	if (one_philo(philos->data, philos) == 1)
		return (0);
	create_thread_each_philo(philos, data);
	create_thread_monitor(philos);
	wait_thread_finish(philos, data);
	mark_sim_finish(philos->data);
	free_resources(data, philos);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 6 && argc != 5)
	{
		printf("Error\n");
		exit(0);
	}
	err_non_int(argc, argv);
	init_data(&data);
	parse_args(argc, argv, &data);
	err_args(argc, &data);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.num_philos);
	if (!data.forks)
		return (1);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_mutex_init(&data.forks[i], NULL);
		i++;
	}
	return (run_simulation(&data));
}
