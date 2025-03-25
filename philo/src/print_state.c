/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:15 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 20:16:44 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "mutex_handler.h"
#include <stdio.h>

void	print_state(t_philo *philo, const char *state)
{
	long	timestamp;

	if (check_stop(philo->table))
		return ;
	lock_safe_mutex(&philo->table->print_mtx);
	timestamp = (get_time() - philo->table->start_time) / 1000;
	printf("%ld %d %s\n", timestamp, philo->id, state);
	unlock_safe_mutex(&philo->table->print_mtx);
}
