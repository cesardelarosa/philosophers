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

static uint64_t	get_time_usec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000ULL) + tv.tv_usec);
}

void	precise_usleep(long ms)
{
	uint64_t	start;
	uint64_t	target;
	uint64_t	current;
	long		remaining;

	start = get_time_usec();
	target = start + (ms * MS);
	while (1)
	{
		current = get_time_usec();
		if (current >= target)
			break ;
		remaining = target - current;
		if (remaining > 1000)
			usleep(remaining / 2);
		else if (remaining > 300)
			usleep(remaining - 200);
		else if (remaining > 50)
			usleep(1);
	}
}
