/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:47:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 12:53:08 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"

bool	to_sleep(t_philo *philo)
{
	if (!check_philo(philo))
		return (false);
	print_state(philo, "is sleeping");
	return (philo_sleep(philo, philo->table->t_sleep));
}
