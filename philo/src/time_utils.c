/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:05:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 13:06:18 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define MS 1000

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)MS) + (tv.tv_usec / MS));
}

void	set_stop(t_table *table, bool value)
{
	pthread_mutex_lock(&table->stop_mtx);
	table->stop = value;
	pthread_mutex_unlock(&table->stop_mtx);
}
