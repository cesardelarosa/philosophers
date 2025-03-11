/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:05:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 21:07:05 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)MS) + (tv.tv_usec / MS));
}

bool	check_stop(t_table *table)
{
	bool	stop;

	pthread_mutex_lock(&table->stop_mtx);
	stop = table->stop;
	pthread_mutex_unlock(&table->stop_mtx);
	return (stop);
}

void	set_stop(t_table *table, bool value)
{
	pthread_mutex_lock(&table->stop_mtx);
	table->stop = value;
	pthread_mutex_unlock(&table->stop_mtx);
}

bool	philo_sleep(t_philo *philo, unsigned int ms)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		if (check_stop(philo->table))
			return (false);
		if ((unsigned int)(get_time() - read_meal_time(philo))
			>= philo->table->t_die)
		{
			print_state(philo, "died");
			set_stop(philo->table, true);
			return (false);
		}
		usleep(100);
	}
	return (true);
}
