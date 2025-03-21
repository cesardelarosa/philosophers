/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 10:34:57 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_mtx);
}

static bool	is_full_count_update(t_philo *philo)
{
	t_table	*table;
	bool	ret;

	if (philo->full)
		return (false);
	philo->full = true;
	table = philo->table;
	pthread_mutex_lock(&table->full_mtx);
	ret = ++table->full_count >= table->n_philos;
	pthread_mutex_unlock(&table->full_mtx);
	return (ret);
}

bool	to_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_stop(table))
		return (false);
	print_state(philo, "is eating");
	update_meal_time(philo);
	return (philo_sleep(philo, table->t_eat)
		&& (table->n_meals == -1
			|| ++philo->meals_eaten < (unsigned int)table->n_meals
			|| !is_full_count_update(philo)));
}
