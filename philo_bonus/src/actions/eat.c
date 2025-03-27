/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 10:30:05 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include "timer.h"
#include <unistd.h>
#include <stdbool.h>

bool	eat(t_philo *philo)
{
	print_status(philo, "is eating");
	sem_wait(philo->table->meal_sem);
	philo->last_meal = get_time();
	sem_post(philo->table->meal_sem);
	usleep(philo->table->t_eat);
	sem_wait(philo->table->meal_sem);
	philo->meals_eaten++;
	if (philo->table->n_meals != -1
		&& philo->meals_eaten >= (unsigned int)philo->table->n_meals
		&& philo->full == 0)
	{
		philo->full = 1;
		sem_post(philo->table->full_sem);
	}
	sem_post(philo->table->meal_sem);
	return (true);
}
