/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 18:08:34 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include <stdbool.h>

bool	take_forks(t_philo *philo)
{
	sem_wait(philo->table->forks_sem);
	print_status(philo, "has taken a fork");
	sem_wait(philo->table->forks_sem);
	print_status(philo, "has taken a fork");
	return (true);
}
