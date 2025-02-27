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

static int	assign_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
	{
		if ((i + 1) % 2 == 0)
		{
			table->philos[i].left_fork = &table->forks[i];
			table->philos[i].right_fork = &table->forks[(i + 1)
				% table->n_philos];
		}
		else
		{
			table->philos[i].left_fork = &table->forks[(i + 1)
				% table->n_philos];
			table->philos[i].right_fork = &table->forks[i];
		}
	}
	return (0);
}

int	init_philosophers(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->n_philos);
	if (!table->philos)
		return (1);
	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].table = table;
		if (init_philo_mutexes(&table->philos[i]))
		{
			while (--i >= 0)
			{
				pthread_mutex_destroy(&table->philos[i].meal_mtx);
				pthread_mutex_destroy(&table->philos[i].state_mtx);
			}
			free(table->philos);
			table->philos = NULL;
			return (1);
		}
	}
	return (assign_forks(table));
}
