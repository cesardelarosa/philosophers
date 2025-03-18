/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:08:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 19:22:55 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "actions.h"

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->last_meal = philo->table->start_time;
	if (philo->table->n_meals == 0)
		set_stop(philo->table, true);
	if (philo->id % 2 == 0)
		usleep(500);
	while (to_think(philo) && to_eat(philo) && to_sleep(philo))
		continue ;
	return (NULL);
}

static unsigned int	create_philo_threads(t_table *table)
{
	unsigned int	created;
	t_philo			*philo;

	created = 0;
	while (created < table->n_philos)
	{
		philo = &table->philos[created];
		if (pthread_create(&philo->thread, NULL, philo_routine, philo) != 0)
		{
			set_stop(table, true);
			break ;
		}
		created++;
	}
	return (created);
}

int	run_simulation(t_table *table)
{
	unsigned int	created;
	unsigned int	i;

	table->start_time = get_time();
	created = create_philo_threads(table);
	i = 0;
	while (i < created)
		pthread_join(table->philos[i++].thread, NULL);
	return (created == table->n_philos);
}
