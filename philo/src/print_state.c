/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:47:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 12:53:23 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "action_utils.h"

void	print_state(t_philo *philo, const char *state)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->print_mtx);
	timestamp = get_time() - philo->table->start_time;
	if (check_philo(philo))
		printf("%-6ld %-3d %s\n", timestamp, philo->id, state);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
