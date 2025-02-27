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
	if (philo->table->stop)
		return ;
	print_state(philo, "is sleeping");
	precise_usleep(philo->table->t_sleep);
}
