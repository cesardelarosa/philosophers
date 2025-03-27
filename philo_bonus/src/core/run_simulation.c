/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 10:31:26 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"
#include "actions.h"
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static void	*meal_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->table->meal_sem);
		if (get_time() - philo->last_meal > philo->table->t_die)
		{
			sem_wait(philo->table->print_sem);
			printf("%lu %d died\n",
				(get_time() - philo->table->start_time) / 1000,
				philo->id);
			exit(1);
		}
		sem_post(philo->table->meal_sem);
		usleep(1000);
	}
	return (NULL);
}

static void	philosopher_routine(t_philo *philo)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, meal_monitor, philo);
	pthread_detach(monitor);
	while (true)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		to_sleep(philo);
	}
	exit(0);
}

int	run_simulation(t_table *table)
{
	unsigned int	i;
	unsigned int	full_count;

	table->start_time = get_time();
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].last_meal = table->start_time;
		table->pids[i] = fork();
		if (table->pids[i] == 0)
			philosopher_routine(&table->philos[i]);
		i++;
	}
	if (table->n_meals != -1)
	{
		full_count = 0;
		while (full_count < table->n_philos)
		{
			sem_wait(table->full_sem);
			full_count++;
		}
	}
	else
		waitpid(-1, NULL, 0);
	i = 0;
	while (i < table->n_philos)
		kill(table->pids[i++], SIGKILL);
	return (true);
}
