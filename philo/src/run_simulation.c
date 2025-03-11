/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:08:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/11 11:10:43 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_philo_threads(t_table *table, unsigned int *i)
{
	*i = 0;
	while (*i < table->n_philos)
	{
		if (pthread_create(&table->philos[*i].thread, NULL,
				philosopher_routine, &table->philos[*i]) != 0)
		{
			set_stop(table, true);
			return (1);
		}
		(*i)++;
	}
	return (0);
}

static void	join_philo_threads(t_table *table, unsigned int i)
{
	while (i-- > 0)
		pthread_join(table->philos[i].thread, NULL);
}

int	run_simulation(t_table *table)
{
	unsigned int	created;

	table->start_time = get_time();
	if (create_philo_threads(table, &created) != 0)
	{
		join_philo_threads(table, created);
		return (1);
	}
	join_philo_threads(table, created);
	return (0);
}
