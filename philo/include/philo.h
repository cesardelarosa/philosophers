/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 23:32:14 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	int					id;
	int					taken;
}	t_fork;

typedef struct s_philo
{
	int					id;
	unsigned int		meals_eaten;
	uint64_t			last_meal;
	int					left_index;
	int					right_index;
	bool				full;
	pthread_t			thread;
	pthread_mutex_t		meal_mtx;
	struct s_table		*table;
}	t_philo;

typedef struct s_table
{
	unsigned int		n_philos;
	uint64_t			t_die;
	uint64_t			t_eat;
	uint64_t			t_sleep;
	long				n_meals;
	unsigned int		full_count;
	bool				stop;
	uint64_t			start_time;
	t_philo				*philos;
	t_fork				*forks;
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		stop_mtx;
	pthread_mutex_t		forks_avail_mtx;
	pthread_mutex_t		full_mtx;
}	t_table;

bool					parse_arguments(int argc, char **argv, t_table *table);
bool					init_simulation(t_table *table);
void					clean_resources(t_table *table);
int						run_simulation(t_table *table);
uint64_t				get_time(void);
bool					philo_sleep(t_philo *philo, uint64_t us);
void					update_meal_time(t_philo *philo);
uint64_t				read_meal_time(t_philo *philo);
bool					to_eat(t_philo *philo);
bool					to_sleep(t_philo *philo);
bool					to_think(t_philo *philo);
void					print_state(t_philo *philo, const char *state);
void					stop(t_table *table);
bool					check_stop(t_table *table);
bool					check_death(t_philo *philo);
void					update_full_count(t_philo *philo);

#endif
