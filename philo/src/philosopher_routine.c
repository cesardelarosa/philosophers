/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:10:17 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 11:02:17 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->meal_mtx);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->meal_mtx);
	to_think(philo);
	if (philo->id % 2 == 0)
		precise_usleep(philo->table->t_eat / 2);
	while (!check_stop(philo->table))
	{
		if (philo->table->n_meals < 0
			|| philo->meals_eaten < philo->table->n_meals)
		{
			to_eat(philo);
			to_sleep(philo);
			to_think(philo);
		}
		else
			precise_usleep(1);
	}
	return (NULL);
}
