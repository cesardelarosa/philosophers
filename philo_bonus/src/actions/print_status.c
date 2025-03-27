/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:01:28 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 08:15:01 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "timer.h"
#include <stdio.h>

void	print_status(t_philo *philo, char *status)
{
	sem_wait(philo->table->print_sem);
	printf("%lu %d %s\n",
		(get_time() - philo->table->start_time) / 1000,
		philo->id, status);
	sem_post(philo->table->print_sem);
}
