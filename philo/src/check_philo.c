/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:05:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 20:02:47 by cesi             ###   ########.fr       */
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
		pthread_mutex_lock(&philo->table->stop_mtx);
		if (!philo->table->stop)
		{
			philo->table->stop = true;
			pthread_mutex_unlock(&philo->table->stop_mtx);
			pthread_mutex_lock(&philo->table->print_mtx);
			printf("%-6ld %-3d %s\n", get_time() - philo->table->start_time,
				philo->id, "died");
			pthread_mutex_unlock(&philo->table->print_mtx);
		}
		else
			pthread_mutex_unlock(&philo->table->stop_mtx);
		return (false);
	}
	return (true);
}

bool	philo_sleep(t_philo *philo, unsigned int ms)
{
	uint64_t	start;
	uint64_t	last_meal;
	uint64_t	remaining;
	uint64_t	sleep_time;

	start = get_time();
	last_meal = read_meal_time(philo);
	remaining = philo->table->t_die - (start - last_meal);
	if (ms >= remaining)
		sleep_time = remaining + 1;
	else
		sleep_time = ms;
	while ((get_time() - start) < sleep_time)
	{
		if (check_stop(philo->table))
			return (false);
		usleep(100);
	}
	return (check_philo(philo));
}
