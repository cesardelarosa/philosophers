/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:01:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 10:51:19 by cde-la-r         ###   ########.fr       */
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
			while (i-- > 0)
				pthread_mutex_destroy(&table->forks[i].mtx);
			free(table->forks);
			table->forks = NULL;
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
