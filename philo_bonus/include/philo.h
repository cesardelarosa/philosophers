/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:57:46 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 18:58:34 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_MAX 200
# define MS 1000

# define ARGS "number_of_philosophers time_to_die time_to_eat time_to_sleep"
# define OPT_ARG "[number_of_times_each_philosopher_must_eat]"

# include <fcntl.h>
# include <limits.h>
# include <semaphore.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	unsigned int		id;
	pid_t				pid;
	uint64_t			last_meal;
	unsigned int		meals_eaten;
	t_table				*table;
}						t_philo;

struct					s_table
{
	unsigned int		n_philos;
	unsigned int		t_die;
	unsigned int		t_eat;
	unsigned int		t_sleep;
	long				n_meals;
	uint64_t			start_time;
	bool				stop;
	t_philo				*philos;
	sem_t				*forks;
	sem_t				*print;
};

int						parse_arguments(int argc, char **argv, t_table *table);
int						init_simulation(t_table *table);
int						run_simulation(t_table *table);
void					clean_resources(t_table *table);
uint64_t				get_time(void);
void					precise_usleep(unsigned int ms);
int						error_handler(const char *msg, t_table *table);
void					print_state(t_philo *philo, const char *state);
void					set_stop(t_table *table, bool value);
void					update_meal_time(t_philo *philo);
uint64_t				read_meal_time(t_philo *philo);
unsigned int			read_meals_eaten(t_philo *philo);
void					add_meal(t_philo *philo);
void					to_eat(t_philo *philo);
void					to_sleep(t_philo *philo);
void					to_think(t_philo *philo, unsigned int t_think);

#endif
