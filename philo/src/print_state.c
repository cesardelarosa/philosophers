/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:53:09 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 10:53:10 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, const char *state)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->print_mtx);
	timestamp = get_time() - philo->table->start_time;
	if (!check_stop(philo->table))
		printf("%-6ld %-3d %s\n", timestamp, philo->id, state);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
