/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:54:49 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 16:46:35 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

static void	cleanup_partial(t_table *table, int fork_count)
{
	int	i;

	i = 0;
	while (i < fork_count)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	table->forks = NULL;
	free(table->philos);
	table->philos = NULL;
	pthread_mutex_destroy(&table->print_mutex);
	free(table);
}

static int	alloc_resources(t_table *table)
{
	table->philos = malloc(sizeof(t_philosopher) * table->n_philosophers);
	if (!table->philos)
		return (1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philosophers);
	if (!table->forks)
	{
		free(table->philos);
		return (1);
	}
	return (0);
}

static int	init_print_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
	{
		free(table->forks);
		free(table->philos);
		return (1);
	}
	return (0);
}

static int	init_forks_and_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			cleanup_partial(table, i);
			return (1);
		}
		table->philos[i].id = i + 1;
		table->philos[i].last_meal = table->start_time;
		table->philos[i].meals_eaten = 0;
		table->philos[i].table = table;
		i++;
	}
	return (0);
}

int	init_simulation(t_table *table)
{
	if (table == NULL)
		return (0);
	table->start_time = get_time_in_ms();
	table->stop = 0;
	if (alloc_resources(table)
		|| init_print_mutex(table)
		|| init_forks_and_philos(table))
	{
		printf("Error initializing simulation\n");
		cleanup_simulation(table);
		return (1);
	}
	return (0);
}
