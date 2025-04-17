/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/18 00:41:34 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"
#include "actions.h"
#include "action_utils.h"

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
	if (!think(philo)
		|| (philo->id % 2 && !smart_sleep(philo, philo->table->t_eat / 2)))
		return (NULL);
	while (take_forks(philo)
		&& eat(philo)
		&& put_forks(philo)
		&& sleep(philo)
		&& think(philo))
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

bool	run_simulation(t_table *table)
{
	unsigned int	i;
	unsigned int	created;

	table->start_time = get_time();
	i = 0;
	while (i < table->n_philos)
		table->philos[i++].last_meal = table->start_time;
	if (table->n_meals == 0)
		stop(table);
	created = create_threads(table);
	i = 0;
	while (i < created)
		pthread_join(table->philos[i++].thread, NULL);
	return (created != table->n_philos);
}
