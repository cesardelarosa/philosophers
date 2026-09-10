/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:32 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 21:05:39 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"

bool	sleep(t_philo *philo)
{
	return (print_state(philo, "is sleeping")
		&& smart_sleep(philo, philo->table->t_sleep));
}
