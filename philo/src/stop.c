/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:12 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 22:59:13 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop(t_table *table)
{
	pthread_mutex_lock(&table->stop_mtx);
	table->stop = true;
	pthread_mutex_unlock(&table->stop_mtx);
}

bool	check_stop(t_table *table)
{
	bool	stop_state;

	pthread_mutex_lock(&table->stop_mtx);
	stop_state = table->stop;
	pthread_mutex_unlock(&table->stop_mtx);
	return (stop_state);
}
