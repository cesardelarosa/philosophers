/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 22:58:43 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (to_think(philo) && to_eat(philo) && to_sleep(philo))
		;
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
		pthread_mutex_lock(&table->philos[i].meal_mtx);
		table->philos[i].last_meal = table->start_time;
		pthread_mutex_unlock(&table->philos[i].meal_mtx);
		i++;
	}
	if (table->n_meals == 0)
		stop(table);
	created = create_threads(table);
	i = 0;
	while (i < created)
		pthread_join(table->philos[i++].thread, NULL);
	return (created != table->n_philos);
}
