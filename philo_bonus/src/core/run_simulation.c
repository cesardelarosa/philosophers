/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 11:44:40 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "timer.h"
#include "monitor.h"
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	*full_monitor(void *arg)
{
	t_monitor_arg	*mon;
	unsigned int	i;

	mon = (t_monitor_arg *)arg;
	i = 0;
	while (i < mon->table->n_philos)
	{
		sem_wait(mon->table->full_sem);
		i++;
	}
	*(mon->all_full) = 1;
	return (NULL);
}

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
			printf("%lu %d died\n", (get_time() - philo->table->start_time)
				/ 1000, philo->id);
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

bool	run_simulation(t_table *table)
{
	unsigned int	i;
	int				status;
	volatile int	all_full;
	pthread_t		full_thread;
	t_monitor_arg	mon_arg;

	all_full = 0;
	mon_arg.table = table;
	mon_arg.all_full = &all_full;
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
		pthread_create(&full_thread, NULL, full_monitor, &mon_arg);
	while (1)
	{
		if (all_full)
			break ;
		if (waitpid(-1, &status, WNOHANG) > 0)
		{
			if ((WIFEXITED(status) && WEXITSTATUS(status) != 0)
				|| WIFSIGNALED(status))
				break ;
		}
		usleep(1000);
	}
	i = 0;
	while (i < table->n_philos)
	{
		kill(table->pids[i], SIGKILL);
		waitpid(table->pids[i], NULL, 0);
		i++;
	}
	return (true);
}
