/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:47:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 17:59:32 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "action_utils.h"

bool	print_state(t_philo *philo, const char *state)
{
	long	timestamp;

	if (!check_philo(philo))
		return (false);
	pthread_mutex_lock(&philo->table->print_mtx);
	timestamp = get_time() - philo->table->start_time;
	printf("%-6ld %-3d %s\n", timestamp, philo->id, state);
	pthread_mutex_unlock(&philo->table->print_mtx);
	return (true);
}
