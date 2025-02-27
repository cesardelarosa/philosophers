/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:48:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 10:48:09 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo_mutexes(t_philo *philo)
{
	if (pthread_mutex_init(&philo->meal_mtx, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&philo->state_mtx, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->meal_mtx);
		return (1);
	}
	return (0);
}

int	init_philosophers(t_table *table)
{
	unsigned int	i;

	table->philos = malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philos)
		return (1);
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].table = table;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->n_philos];
		if (init_philo_mutexes(&table->philos[i]))
		{
			destroy_philos(table, i);
			return (1);
		}
		i++;
	}
	return (0);
}
