/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:15 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 17:22:02 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

static int	check_philosopher_death(t_table *table, int index)
{
	long			current_time;
	t_philosopher	*philo;

	current_time = get_time_in_ms();
	philo = &table->philos[index];
	if (current_time - philo->last_meal > table->t_die)
	{
		table->stop = 1;
		pthread_mutex_lock(&table->print_mutex);
		printf("%ld %d died\n", current_time - table->start_time, philo->id);
		pthread_mutex_unlock(&table->print_mutex);
		return (1);
	}
	return (0);
}

static int	check_any_death(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosophers)
	{
		if (check_philosopher_death(table, i++))
			return (1);
	}
	return (0);
}

static int	count_satisfied_philosophers(t_table *table)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < table->n_philosophers)
		count += (table->philos[i++].meals_eaten >= table->n_meals);
	return (count);
}

static int	check_all_satisfied(t_table *table, int satisfied_count)
{
	if (satisfied_count == table->n_philosophers)
	{
		table->stop = 1;
		pthread_mutex_lock(&table->print_mutex);
		printf("All philosophers have eaten enough\n");
		pthread_mutex_unlock(&table->print_mutex);
		return (1);
	}
	return (0);
}

void	*monitor_philosophers(void *arg)
{
	t_table	*table;
	int		satisfied_count;

	table = (t_table *)arg;
	while (!table->stop)
	{
		usleep(1000);
		if (check_any_death(table))
			break ;
		if (table->n_meals == -1)
			continue ;
		satisfied_count = count_satisfied_philosophers(table);
		if (check_all_satisfied(table, satisfied_count))
			break ;
	}
	return (NULL);
}
