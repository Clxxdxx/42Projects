/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:23 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/07 13:00:24 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void init_time(t_data *data)
{
    struct timeval start;
    gettimeofday(&start, NULL);
    data->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000); 
}