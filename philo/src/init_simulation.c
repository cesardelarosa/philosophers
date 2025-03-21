/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:50 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 22:05:46 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

static bool	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->print_mtx, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&table->stop_mtx, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&table->full_mtx, NULL) != 0)
		return (false);
	return (true);
}

static bool	init_forks(t_table *table)
{
	unsigned int	i;

	table->forks = malloc(sizeof(t_fork) * table->n_philos);
	if (!table->forks)
		return (false);
	i = 0;
	while (i < table->n_philos)
	{
		table->forks[i].id = i;
		table->forks[i].taken = 0;
		if (pthread_mutex_init(&table->forks[i].mtx, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

static bool	init_philosophers(t_table *table)
{
	unsigned int	i;

	table->philos = malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philos)
		return (false);
	i = 0;
	while (i < table->n_philos)
	{
		memset(&table->philos[i], 0, sizeof(t_philo));
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		if (i < (i + 1) % table->n_philos)
		{
			table->philos[i].first_fork = i;
			table->philos[i].second_fork = (i + 1) % table->n_philos;
		}
		else
		{
			table->philos[i].first_fork = (i + 1) % table->n_philos;
			table->philos[i].second_fork = i;
		}
		pthread_mutex_init(&table->philos[i++].meal_mtx, NULL);
	}
	return (true);
}

bool	init_simulation(t_table *table)
{
	if (!init_mutexes(table))
		return (false);
	if (!init_forks(table))
		return (false);
	if (!init_philosophers(table))
		return (false);
	return (true);
}
