/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 20:55:34 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "mutex_handler.h"

static bool	handle_single_philo(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	lock_safe_mutex(&philo->first_fork->mtx);
	if (philo->first_fork->taken == 0)
	{
		philo->first_fork->taken = 1;
		unlock_safe_mutex(&philo->first_fork->mtx);
		print_state(philo, "has taken a fork");
	}
	else
		unlock_safe_mutex(&philo->first_fork->mtx);
	smart_sleep(philo, table->t_die);
	return (false);
}

static uint64_t	calc_wait_time(t_philo *philo)
{
	uint64_t	current;
	uint64_t	elapsed;
	uint64_t	min_elapsed;
	double		hunger;
	t_table		*table;

	table = philo->table;
	current = get_time();
	elapsed = current - philo->last_meal;
	min_elapsed = table->t_eat + table->t_sleep;
	if (elapsed >= table->t_die)
		return (0);
	if (elapsed <= min_elapsed)
		return (1000);
	if (table->t_die <= min_elapsed)
		return (0);
	hunger = (double)(elapsed - min_elapsed) / (table->t_die - min_elapsed);
	return ((uint64_t)(1000 * (1.0 - (hunger * hunger))));
}

bool	take_forks(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_stop(table))
		return (false);
	if (table->n_philos == 1)
		return (handle_single_philo(philo));
	while (smart_sleep(philo, calc_wait_time(philo)))
	{
		lock_safe_mutex(&philo->first_fork->mtx);
		lock_safe_mutex(&philo->second_fork->mtx);
		if (philo->first_fork->taken == 0 && philo->second_fork->taken == 0)
		{
			philo->first_fork->taken = 1;
			philo->second_fork->taken = 1;
			unlock_safe_mutex(&philo->second_fork->mtx);
			unlock_safe_mutex(&philo->first_fork->mtx);
			print_state(philo, "has taken a fork");
			print_state(philo, "has taken a fork");
			return (true);
		}
		unlock_safe_mutex(&philo->second_fork->mtx);
		unlock_safe_mutex(&philo->first_fork->mtx);
	}
	return (false);
}
