/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 17:27:10 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ARGS "number_of_philosophers time_to_die time_to_eat time_to_sleep"
# define OPT_ARG "[number_of_times_each_philosopher_must_eat]"

# define START_ERROR "Error starting simulation"

# include <pthread.h>

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	long			last_meal;
	int				meals_eaten;
	struct s_table	*table;
}	t_philosopher;

typedef struct s_table
{
	int				n_philosophers;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	long			start_time;
	int				stop;
	pthread_t		monitor;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
}	t_table;

int		init_simulation(t_table *table);
void	cleanup_simulation(t_table *table);

void	*philosopher_routine(void *arg);
void	*monitor_philosophers(void *arg);

long	get_time_in_ms(void);

t_table	*parser(int argc, char **argv);

#endif
