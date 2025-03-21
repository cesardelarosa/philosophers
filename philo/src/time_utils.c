/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:18 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 23:43:53 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000ULL + tv.tv_usec);
}

uint64_t	read_meal_time(t_philo *philo)
{
	uint64_t	last_meal;

	pthread_mutex_lock(&philo->meal_mtx);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mtx);
	return (last_meal);
}

bool	philo_sleep(t_philo *philo, uint64_t us)
{
	uint64_t	start;
	uint64_t	available;
	uint64_t	duration;
	uint64_t	remaining;

	start = get_time();
	available = philo->table->t_die - (start - read_meal_time(philo));
	if (us >= available)
		duration = available;
	else
		duration = us;
	while (get_time() - start < duration)
	{
		if (check_stop(philo->table))
			return (false);
		remaining = duration - (get_time() - start);
		if (remaining < 100)
			usleep(remaining);
		else
			usleep(100);
	}
	return (!check_death(philo));
}
