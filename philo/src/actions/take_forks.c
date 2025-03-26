/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 14:36:39 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include "timer.h"

static bool	check_and_lock_fork(t_fork *fork, int id)
{
	if (!lock_safe_mutex(&fork->mtx))
		return (false);
	if (fork->taken || fork->stamp == id)
	{
		unlock_safe_mutex(&fork->mtx);
		return (false);
	}
	return (true);
}

static bool	take_single_fork(t_philo *philo, t_fork *fork)
{
	fork->taken = 1;
	fork->stamp = philo->id;
	unlock_safe_mutex(&fork->mtx);
	return (print_state(philo, "has taken a fork"));
}

bool	take_forks(t_philo *philo)
{
	bool	one_fork;

	one_fork = philo->first_fork == philo->second_fork;
	while (smart_sleep(philo, 100))
	{
		if (!check_and_lock_fork(philo->first_fork, philo->id))
			continue ;
		if (!one_fork && !check_and_lock_fork(philo->second_fork, philo->id))
		{
			unlock_safe_mutex(&philo->first_fork->mtx);
			continue ;
		}
		if (!take_single_fork(philo, philo->first_fork))
		{
			unlock_safe_mutex(&philo->second_fork->mtx);
			continue ;
		}
		if (!one_fork && take_single_fork(philo, philo->second_fork))
			return (true);
	}
	return (false);
}
