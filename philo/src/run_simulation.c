/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 21:06:05 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "mutex_handler.h"
#include <pthread.h>
#include "actions.h"

static void	stop(t_table *table)
{
	lock_safe_mutex(&table->stop_mtx);
	table->stop = true;
	unlock_safe_mutex(&table->stop_mtx);
}

static void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (think(philo)
		&& take_forks(philo)
		&& eat(philo)
		&& put_forks(philo)
		&& sleep(philo))
		continue ;
	stop(philo->table);
	return (NULL);
}

static unsigned int	create_threads(t_table *table)
{
	unsigned int	created;

	created = 0;
	while (created < table->n_philos)
	{
		if (pthread_create(&table->philos[created].thread, NULL,
				philosopher_routine, &table->philos[created]) != 0)
		{
			stop(table);
			break ;
		}
		created++;
	}
	return (created);
}

int	run_simulation(t_table *table)
{
	unsigned int	i;
	unsigned int	created;

	table->start_time = get_time();
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].last_meal = table->start_time;
		i++;
	}
	if (table->n_meals == 0)
		stop(table);
	created = create_threads(table);
	i = 0;
	while (i < created)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	return (created != table->n_philos);
}
