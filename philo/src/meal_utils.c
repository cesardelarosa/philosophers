/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:10:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 13:14:52 by cde-la-r         ###   ########.fr       */
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
