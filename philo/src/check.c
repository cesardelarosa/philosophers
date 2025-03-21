/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:36 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 23:51:18 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_stop(t_table *table)
{
	bool	stop_state;

	pthread_mutex_lock(&table->stop_mtx);
	stop_state = table->stop;
	pthread_mutex_unlock(&table->stop_mtx);
	return (stop_state);
}

bool	check_death(t_philo *philo)
{
	uint64_t	current;

	current = get_time();
	if (current - read_meal_time(philo) >= philo->table->t_die)
	{
		pthread_mutex_lock(&philo->table->print_mtx);
		pthread_mutex_lock(&philo->table->stop_mtx);
		if (!philo->table->stop)
		{
			philo->table->stop = true;
			printf("%ld %d died\n", (current - philo->table->start_time) / 1000,
				philo->id);
		}
		pthread_mutex_unlock(&philo->table->stop_mtx);
		pthread_mutex_unlock(&philo->table->print_mtx);
		return (true);
	}
	return (false);
}
