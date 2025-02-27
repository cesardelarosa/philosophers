/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:08:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/26 14:15:26 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_philo_threads(t_table *table, int *i)
{
	*i = -1;
	while (++(*i) < table->n_philos)
	{
		if (pthread_create(&table->philos[*i].thread, NULL,
				philosopher_routine, &table->philos[*i]) != 0)
		{
			set_stop(table, true);
			return (1);
		}
	}
	return (0);
}

static void	join_philo_threads(t_table *table, int i)
{
	while (i-- > 0)
		pthread_join(table->philos[i].thread, NULL);
}

int	run_simulation(t_table *table)
{
	int	created;

	table->start_time = get_time();
	if (create_philo_threads(table, &created) != 0)
	{
		join_philo_threads(table, created);
		return (1);
	}
	if (pthread_create(&table->monitor, NULL, monitor_routine, table) != 0)
	{
		set_stop(table, true);
		join_philo_threads(table, created);
		return (1);
	}
	join_philo_threads(table, created);
	pthread_join(table->monitor, NULL);
	return (0);
}
