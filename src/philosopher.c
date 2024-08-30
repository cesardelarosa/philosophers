/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:20:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/30 09:20:16 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Philosopher %d is thinking\n", philo->id);
	usleep(1000);
	printf("Philosopher %d is done thinking\n", philo->id);
	return (NULL);
}
