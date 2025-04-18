/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:18 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/18 12:12:14 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include "timer.h"
#include <unistd.h>
#include <stdio.h>

#define THRESHOLD 1000

static bool	check_death(t_philo *philo)
{
	uint64_t			current;
	unsigned long long	ms;

	current = get_time();
	if (current - philo->last_meal >= philo->table->t_die)
	{
		lock_safe_mutex(&philo->table->print_mtx);
		lock_safe_mutex(&philo->table->stop_mtx);
		if (!philo->table->stop)
		{
			philo->table->stop = true;
			ms = (current - philo->table->start_time) / 1000;
			printf("%llu %d died\n", ms, philo->id);
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
	uint64_t	remaining;
	uint64_t	elapsed;

	start = get_time();
	elapsed = start - philo->last_meal;
	if (elapsed >= philo->table->t_die)
		return (!check_death(philo));
	available = philo->table->t_die - elapsed;
	if (us >= available)
		us = available;
	while (get_time() - start < us)
	{
		if (check_stop(philo->table))
			return (false);
		remaining = us - (get_time() - start);
		if (remaining < THRESHOLD)
			usleep(remaining);
		else
			usleep(THRESHOLD);
	}
	return (!check_death(philo));
}
