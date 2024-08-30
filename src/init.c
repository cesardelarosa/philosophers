/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:19:39 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/30 09:23:25 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_resources(pthread_t **threads, pthread_mutex_t **forks, t_philo **philos, int num_philos)
{
	int	i;

	*threads = malloc(sizeof(pthread_t) * num_philos);
	*forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	*philos = malloc(sizeof(t_philo) * num_philos);
	if (!*threads || !*forks || !*philos)
		return (1);
	i = 0;
	while (i < num_philos)
		pthread_mutex_init(&(*forks)[i++], NULL);
	return (0);
}

void	create_philosophers(pthread_t *threads, t_philo *philos, pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % num_philos];
		pthread_create(&threads[i], NULL, philosopher, &philos[i]);
		i++;
	}
}
