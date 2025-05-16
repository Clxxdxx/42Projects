/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:00:44 by clalopez          #+#    #+#             */
/*   Updated: 2025/05/16 16:17:33 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_C
# define PHILO_C
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
void	init_data(t_data *data);
t_philo				init_philo(int id, t_data *data, pthread_mutex_t *left_fork,
						pthread_mutex_t *right_fork);

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

#endif

// PSEUDOCODIGO
/* main():
	X parsear_argumentos()
	X init_data()
	X init_philos()
	X crear_forks()
	X iniciar_tiempo()
	X crear_hilos_para_cada_filosofo()
	X crear_hilo_monitor()
	X esperar_a_que_terminen_los_hilos()
	X liberar_recursos()

X	filosofo_rutina(philo):
	si philo.id es impar:
		esperar_un_pequeño_tiempo()

	mientras simulacion_no_termina:
		pensar()
		tomar_tenedores(philo)
		comer()
		soltar_tenedores(philo)
		dormir()

X	tomar_tenedores(philo):
	lock(philo.left_fork)
	imprimir("ha tomado un tenedor")
	lock(philo.right_fork)
	imprimir("ha tomado un tenedor")

x	comer(philo):
	actualizar(philo.last_meal_time)
	imprimir("está comiendo")
	dormir(time_to_eat)
	incrementar(philo.meals_eaten)

X	soltar_tenedores(philo):
	unlock(philo.left_fork)
	unlock(philo.right_fork)

X	pensar(void), dormir():
	imprimir_estado()
	dormir(el_tiempo_correspondiente)

	mientras simulacion_no_termina:
		para cada filosofo:
			si (ahora - last_meal_time) > time_to_die:
				imprimir("ha muerto")
				marcar_simulacion_terminada()
		si todos han comido suficientes veces:
			marcar_simulacion_terminada() */
