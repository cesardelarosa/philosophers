/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:01:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 18:30:43 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_table *table)
{
	unsigned int	i;

	table->forks = malloc(sizeof(t_fork) * table->n_philos);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->n_philos)
	{
		table->forks[i].id = i + 1;
		if (pthread_mutex_init(&table->forks[i].mtx, NULL) != 0)
		{
			destroy_forks(table, i);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->print_mtx, NULL) != 0)
		return (1);
	table->print_mtx_init = 1;
	if (pthread_mutex_init(&table->stop_mtx, NULL) != 0)
		return (1);
	table->stop_mtx_init = 1;
	if (pthread_mutex_init(&table->full_mtx, NULL) != 0)
		return (1);
	table->full_mtx_init = 1;
	return (0);
}

static int	init_philo_mutexes(t_philo *philo)
{
	if (pthread_mutex_init(&philo->meal_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->state_mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->meal_mtx);
		return (1);
	}
	return (0);
}

static int	init_philosophers(t_table *table)
{
	unsigned int	i;

	table->philos = malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philos)
		return (1);
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->n_philos];
		if (init_philo_mutexes(&table->philos[i]))
		{
			destroy_philos(table, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_simulation(t_table *table)
{
	if (table->n_philos < 1 || table->n_philos > PHILO_MAX)
		return (error_handler("Invalid philosophers number", table));
	if (init_mutexes(table))
		return (error_handler("Mutex initialization failed", table));
	if (init_forks(table))
		return (error_handler("Forks initialization failed", table));
	if (init_philosophers(table))
		return (error_handler("Philosophers initialization failed", table));
	table->stop = false;
	return (0);
}
