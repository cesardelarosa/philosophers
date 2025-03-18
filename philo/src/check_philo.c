/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:05:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 13:05:16 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_stop(t_table *table)
{
	bool	stop;

	pthread_mutex_lock(&table->stop_mtx);
	stop = table->stop;
	pthread_mutex_unlock(&table->stop_mtx);
	return (stop);
}

static uint64_t	read_meal_time(t_philo *philo)
{
	uint64_t	last_meal;

	pthread_mutex_lock(&philo->meal_mtx);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mtx);
	return (last_meal);
}

bool	check_philo(t_philo *philo)
{
	if (check_stop(philo->table))
		return (false);
	if ((unsigned int)(get_time() - read_meal_time(philo))
		>= philo->table->t_die)
	{
		pthread_mutex_lock(&philo->table->print_mtx);
		pthread_mutex_lock(&philo->table->stop_mtx);
		philo->table->stop = true;
		printf("%-6ld %-3d %s\n", get_time() - philo->table->start_time,
			philo->id, "died");
		pthread_mutex_unlock(&philo->table->stop_mtx);
		pthread_mutex_unlock(&philo->table->print_mtx);
		return (false);
	}
	return (true);
}

bool	philo_sleep(t_philo *philo, unsigned int ms)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		if (check_philo(philo) == false)
			return (false);
		usleep(100);
	}
	return (true);
}
