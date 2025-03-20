/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:32 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 22:59:34 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	to_sleep(t_philo *philo)
{
	if (check_stop(philo->table))
		return (false);
	print_state(philo, "is sleeping");
	return (philo_sleep(philo, philo->table->t_sleep));
}
