/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:19:57 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/30 09:24:17 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philosophers(pthread_t *threads, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
		pthread_join(threads[i++], NULL);
}

void	cleanup_resources(pthread_t *threads, pthread_mutex_t *forks, t_philo *philos, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
		pthread_mutex_destroy(&forks[i++]);
	free(threads);
	free(forks);
	free(philos);
}
