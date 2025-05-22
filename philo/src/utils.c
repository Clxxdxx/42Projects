/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:15:26 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/22 15:53:28 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	simulation_has_ended(t_data *data)
{
	int	ended;

	pthread_mutex_lock(&data->end_mutex);
	ended = data->simulation_ended;
	pthread_mutex_unlock(&data->end_mutex);
	return (ended);
}

void	init_time(t_data *data)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	data->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
}

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	mark_sim_finish(t_data *data)
{
	pthread_mutex_lock(&data->end_mutex);
	data->simulation_ended = 1;
	pthread_mutex_unlock(&data->end_mutex);
	pthread_mutex_lock(&data->print_mutex);
	printf("Simulation has finished\n");
	pthread_mutex_unlock(&data->print_mutex);
	return ;
}

int	convert_to_int(const char *nptr)
{
	int	i;
	int	result;
	int	signo;

	result = 0;
	signo = 1;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		signo = -1;
		i++;
	}
	else if (nptr[i] == '+')
	{
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * signo);
}
