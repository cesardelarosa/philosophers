/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 13:18:00 by cde-la-r         ###   ########.fr       */
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
	unsigned int	id;
	pthread_mutex_t	mtx;
}					t_fork;

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	uint64_t		last_meal;
	unsigned int	meals_eaten;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	state_mtx;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	unsigned int	n_philos;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	long			n_meals;
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
void				destroy_philos(t_table *table, unsigned int n_created);
uint64_t			get_time(void);
void				precise_usleep(unsigned int ms);
int					error_handler(const char *msg, t_table *table);
void				print_state(t_philo *philo, const char *state);
bool				check_stop(t_table *table);
void				set_stop(t_table *table, bool value);
void				*philosopher_routine(void *arg);
void				*monitor_routine(void *arg);
void				update_meal_time(t_philo *philo);
uint64_t			read_meal_time(t_philo *philo);
unsigned int		read_meals_eaten(t_philo *philo);
void				add_meal(t_philo *philo);
void				to_eat(t_philo *philo);
void				to_sleep(t_philo *philo);
void				to_think(t_philo *philo, unsigned int t_think);

#endif
