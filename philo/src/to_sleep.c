/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:31:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/26 17:20:33 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	to_sleep(t_philo *philo)
{
	if (check_stop(philo->table))
		return ;
	print_state(philo, "is sleeping");
	philo_sleep(philo, philo->table->t_sleep);
}
