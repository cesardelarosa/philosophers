/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 20:28:15 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_full_count_update(t_philo *philo)
{
	t_table	*table;
	bool	ret;

	if (philo->full)
		return (false);
	philo->full = true;
	table = philo->table;
	lock_safe_mutex(&table->full_mtx);
	ret = (++table->full_count >= table->n_philos);
	unlock_safe_mutex(&table->full_mtx);
	return (ret);
}

bool	to_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_stop(table))
		return (false);
	print_state(philo, "is eating");
	philo->last_meal = get_time();
	return (smart_sleep(philo, table->t_eat)
		&& (table->n_meals == -1
			|| ++philo->meals_eaten < (unsigned int)table->n_meals
			|| !is_full_count_update(philo)));
}
