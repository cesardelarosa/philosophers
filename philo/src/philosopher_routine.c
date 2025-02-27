/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:10:17 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 13:20:45 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	calc_think_time(t_philo *philo)
{
	unsigned int	elapsed;

	elapsed = (unsigned int)(get_time() - read_meal_time(philo));
	if (philo->table->t_die > elapsed + philo->table->t_eat)
		return ((philo->table->t_die - elapsed - philo->table->t_eat) / 2 + 1);
	return (1);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	update_meal_time(philo);
	if (philo->id % 2 == 0)
		to_think(philo, 0);
	else
		to_think(philo, calc_think_time(philo));
	while (!check_stop(philo->table))
	{
		if (philo->table->n_meals < 0
			|| read_meals_eaten(philo) < (unsigned int)philo->table->n_meals)
		{
			to_eat(philo);
			to_sleep(philo);
			to_think(philo, calc_think_time(philo));
		}
		else
			precise_usleep(1);
	}
	return (NULL);
}
