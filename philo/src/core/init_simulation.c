/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:50 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 23:40:33 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdlib.h>
#include <string.h>

static void	assign_forks(t_philo *philo, t_table *table, unsigned int i)
{
	int	left;
	int	right;

	left = i;
	right = (i + 1) % table->n_philos;
	if (left < right)
	{
		philo->first_fork = &table->forks[left];
		philo->second_fork = &table->forks[right];
	}
	else
	{
		philo->first_fork = &table->forks[right];
		philo->second_fork = &table->forks[left];
	}
}

static bool	init_mutexes(t_table *table)
{
	if (!init_safe_mutex(&table->print_mtx))
		return (false);
	if (!init_safe_mutex(&table->stop_mtx))
	{
		destroy_safe_mutex(&table->print_mtx);
		return (false);
	}
	if (!init_safe_mutex(&table->full_mtx))
	{
		destroy_safe_mutex(&table->print_mtx);
		destroy_safe_mutex(&table->stop_mtx);
		return (false);
	}
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
		if (!init_safe_mutex(&table->forks[i].mtx))
		{
			while (i > 0)
			{
				i--;
				destroy_safe_mutex(&table->forks[i].mtx);
			}
			free(table->forks);
			table->forks = NULL;
			return (false);
		}
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
		assign_forks(&table->philos[i], table, i);
		i++;
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
