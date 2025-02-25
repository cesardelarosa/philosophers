/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:44:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 14:45:14 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->table->stop)
	{
		to_think(philo);
		to_eat(philo);
		to_sleep(philo);
	}
	return (NULL);
}
