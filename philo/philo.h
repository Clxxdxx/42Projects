/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:20 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/22 16:11:32 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_to_eat;
	int				simulation_ended;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex_meal;
	t_data			*data;
}					t_philo;

int					convert_to_int(const char *nptr);
int					simulation_has_ended(t_data *data);
void				mark_sim_finish(t_data *data);
void				parse_args(int argc, char **argv, t_data *data);
void				create_forks(t_data *data, t_philo *philo);
void				free_resources(t_data *data, t_philo *philos);

// TIME
void				init_time(t_data *data);
long				get_time_in_ms(void);

// INITIALIZERS
void				init_data(t_data *data);
void				init_philos(t_data *data, t_philo *philos);

// THREADS
void				create_thread_monitor(t_philo *philos);
void				create_thread_each_philo(t_philo *philo, t_data *data);
void				wait_thread_finish(t_philo *philo, t_data *data);

// PHILO ACTIONS
void				sleep_philo(t_philo *philo);
void				think_philo(t_philo *philo);
void				eat_philo(t_philo *philo);

// FORKS FUNCTIONS
void				get_forks(t_philo *philo);
void				drop_forks(t_philo *philo);

// ERRORS
void				err_args(int argc, t_data *data);
void				err_non_int(int argc, char **argv);

#endif
