/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:15 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 23:52:55 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, const char *state)
{
	long	timestamp;

	if (check_stop(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->print_mtx);
	timestamp = (get_time() - philo->table->start_time) / 1000;
	printf("%ld %d %s\n", timestamp, philo->id, state);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
