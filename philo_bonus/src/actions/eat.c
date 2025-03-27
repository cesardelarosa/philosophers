/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 08:13:59 by cesi             ###   ########.fr       */
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
	philo->meals_eaten++;
	sem_post(philo->table->meal_sem);
	usleep(philo->table->t_eat);
	return (true);
}
