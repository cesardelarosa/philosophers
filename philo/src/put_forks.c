/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 09:57:58 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	put_forks(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_stop(table))
		return (false);
	pthread_mutex_lock(&table->forks[philo->first_fork].mtx);
	pthread_mutex_lock(&table->forks[philo->second_fork].mtx);
	table->forks[philo->first_fork].taken = 0;
	table->forks[philo->second_fork].taken = 0;
	pthread_mutex_unlock(&table->forks[philo->second_fork].mtx);
	pthread_mutex_unlock(&table->forks[philo->first_fork].mtx);
	return (true);
}
