/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:18 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 20:56:07 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define THRESHOLD 1000

static bool	check_death(t_philo *philo)
{
	uint64_t		current;
	unsigned int	ms;

	current = get_time();
	if (current - philo->last_meal >= philo->table->t_die)
	{
		lock_safe_mutex(&philo->table->print_mtx);
		lock_safe_mutex(&philo->table->stop_mtx);
		if (!philo->table->stop)
		{
			philo->table->stop = true;
			ms = (current - philo->table->start_time) / 1000;
			printf("%d %d died\n", ms, philo->id);
		}
		unlock_safe_mutex(&philo->table->stop_mtx);
		unlock_safe_mutex(&philo->table->print_mtx);
		return (true);
	}
	return (false);
}

bool	smart_sleep(t_philo *philo, uint64_t us)
{
	uint64_t	start;
	uint64_t	available;
	uint64_t	duration;
	uint64_t	remaining;

	start = get_time();
	available = philo->table->t_die - (start - philo->last_meal);
	if (us >= available)
		duration = available;
	else
		duration = us;
	while (get_time() - start < duration)
	{
		if (check_stop(philo->table))
			return (false);
		remaining = duration - (get_time() - start);
		if (remaining < THRESHOLD)
			usleep(remaining);
		else
			usleep(THRESHOLD);
	}
	return (!check_death(philo));
}
