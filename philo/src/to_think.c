/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:31:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 19:15:07 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	calc_think_time(t_philo *philo)
{
	unsigned int	elapsed;

	if (philo->meals_eaten == 0 && philo->id % 2 == 0)
		return (1);
	elapsed = (unsigned int)(get_time() - read_meal_time(philo));
	return ((philo->table->t_die - elapsed - philo->table->t_eat) / 2 + 1);
}

void	to_think(t_philo *philo)
{
	unsigned int	t_think;

	if (check_stop(philo->table))
		return ;
	print_state(philo, "is thinking");
	t_think = calc_think_time(philo);
	if (t_think > 0)
		philo_sleep(philo, t_think);
}
