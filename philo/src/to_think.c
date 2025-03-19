/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:31:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 19:29:45 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned int	calc_think_time(t_philo *philo)
{
	if (philo->meals_eaten == 0 && (philo->id + philo->meals_eaten) % 2 == 0)
		return (philo->table->t_eat - 1);
	return (0);
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
