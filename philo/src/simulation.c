/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:15 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 10:56:27 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void	*monitor_philosophers(void *arg)
{
	t_table	*table;
	int		n_satisfied;
	int		i;

	table = (t_table *)arg;
	while (!table->stop)
	{
		n_satisfied = 0;
		i = 0;
		while (i < table->n_philosophers)
		{
			if (get_time_in_ms() - table->philos[i].last_meal > table->t_die)
			{
				table->stop = 1;
				pthread_mutex_lock(&table->print_mutex);
				printf("%ld %d died\n", get_time_in_ms() - table->start_time, table->philos[i].id);
				pthread_mutex_unlock(&table->print_mutex);
				return (NULL);
			}
			n_satisfied += (table->philos[i].meals_eaten >= table->n_meals);
			i++;
		}
		if (n_satisfied == table->n_philosophers)
		{
			table->stop = 1;
			pthread_mutex_lock(&table->print_mutex);
			printf("All philosophers have eaten enough\n");
			pthread_mutex_unlock(&table->print_mutex);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

static void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->table->stop)
	{
		to_think(philo);
		to_eat(philo);
		to_sleep(philo);
	}
	return (NULL);
}

void	join_threads(t_philosopher *philo, int n)
{
	int	i;

	i = 0;
	while (i < n)
		pthread_join(philo[i++].thread, NULL);
}

int	start_simulation(t_table *table)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < table->n_philosophers)
	{
		if (pthread_create(&table->philos[i].thread, NULL, philosopher_routine,
				&table->philos[i]))
		{
			table->stop = 1;
			join_threads(table->philos, i);
			return (1);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_philosophers, table))
	{
		table->stop = 1;
		join_threads(table->philos, table->n_philosophers);
		return (1);
	}
	join_threads(table->philos, table->n_philosophers);
	pthread_join(monitor, NULL);
	return (0);
}

void	cleanup_simulation(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->n_philosophers)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
	}
	pthread_mutex_destroy(&table->print_mutex);
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
}
