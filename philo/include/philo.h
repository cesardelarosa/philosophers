/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 10:49:14 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_MAX 200
# define MS 1000

# define ARGS "number_of_philosophers time_to_die time_to_eat time_to_sleep"
# define OPT_ARG "[number_of_times_each_philosopher_must_eat]"

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mtx;
}					t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	uint64_t		last_meal;
	int				meals_eaten;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	state_mtx;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				n_philos;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				n_meals;
	uint64_t		start_time;
	bool			stop;
	pthread_t		monitor;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	stop_mtx;
	bool			print_mtx_init;
	bool			stop_mtx_init;
}					t_table;

int					parse_arguments(int argc, char **argv, t_table *table);
int					init_philosophers(t_table *table);
int					init_simulation(t_table *table);
int					run_simulation(t_table *table);
void				clean_resources(t_table *table);
uint64_t			get_time(void);
void				precise_usleep(long ms);
int					error_handler(const char *msg, t_table *table);
void				print_state(t_philo *philo, const char *state);
bool				check_stop(t_table *table);
void				set_stop(t_table *table, bool value);
void				*philosopher_routine(void *arg);
void				*monitor_routine(void *arg);
void				to_eat(t_philo *philo);
void				to_sleep(t_philo *philo);
void				to_think(t_philo *philo);

#endif
