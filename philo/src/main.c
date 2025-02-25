/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:21:04 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 17:21:05 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void	cleanup_simulation(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->n_philosophers)
			pthread_mutex_destroy(&table->forks[i++]);
		free(table->forks);
		table->forks = NULL;
	}
	pthread_mutex_destroy(&table->print_mutex);
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
	free(table);
	table = NULL;
}

int	stop_simulation(t_table *table, int n_threads, char *error)
{
	int	i;

	table->stop = 1;
	i = 0;
	while (i < n_threads)
		pthread_join(table->philos[i++].thread, NULL);
	pthread_join(table->monitor, NULL);
	cleanup_simulation(table);
	if (error)
	{
		printf("%s", error);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	t_table			*table;
	t_philosopher	*philo;

	table = parser(argc, argv);
	if (init_simulation(table))
		return (1);
	i = 0;
	while (i < table->n_philosophers)
	{
		philo = &table->philos[i];
		if (pthread_create(&philo->thread, NULL, philosopher_routine, philo))
			return (stop_simulation(table, i, START_ERROR));
		i++;
	}
	if (pthread_create(&table->monitor, NULL, monitor_philosophers, table))
		return (stop_simulation(table, table->n_philosophers, START_ERROR));
	return (stop_simulation(table, table->n_philosophers, NULL));
}
