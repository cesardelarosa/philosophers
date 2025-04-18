/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:15 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/18 10:52:50 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include "timer.h"
#include <stdio.h>

bool	print_state(t_philo *philo, const char *state)
{
	unsigned long long	timestamp;

	lock_safe_mutex(&philo->table->print_mtx);
	if (check_stop(philo->table))
	{
		unlock_safe_mutex(&philo->table->print_mtx);
		return (false);
	}
	timestamp = (get_time() - philo->table->start_time) / 1000;
	printf("%llu %d %s\n", timestamp, philo->id, state);
	unlock_safe_mutex(&philo->table->print_mtx);
	return (true);
}
