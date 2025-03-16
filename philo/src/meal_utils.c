/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:10:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 18:08:37 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_mtx);
}

void	add_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->meals_eaten++;
	if (philo->table->n_meals != -1
		&& philo->meals_eaten == (unsigned int)philo->table->n_meals
		&& !philo->full)
	{
		philo->full = true;
		pthread_mutex_lock(&philo->table->full_mtx);
		philo->table->full_count++;
		pthread_mutex_unlock(&philo->table->full_mtx);
	}
	pthread_mutex_unlock(&philo->meal_mtx);
}

uint64_t	read_meal_time(t_philo *philo)
{
	uint64_t	last_meal;

	pthread_mutex_lock(&philo->meal_mtx);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mtx);
	return (last_meal);
}

unsigned int	read_meals_eaten(t_philo *philo)
{
	unsigned int	meals_eaten;

	pthread_mutex_lock(&philo->meal_mtx);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal_mtx);
	return (meals_eaten);
}
