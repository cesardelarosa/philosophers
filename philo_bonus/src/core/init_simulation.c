/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:50 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 10:52:16 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "timer.h"
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

bool	init_simulation(t_table *table)
{
	unsigned int	i;

	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
	sem_unlink("/meal_sem");
	sem_unlink("/full_sem");
	sem_unlink("/room_sem");
	table->forks_sem = sem_open("/forks_sem", O_CREAT, 0644, table->n_philos);
	table->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	table->meal_sem = sem_open("/meal_sem", O_CREAT, 0644, 1);
	table->room_sem = sem_open("/room_sem", O_CREAT, 0644,
			table->n_philos - 1 + (table->n_philos < 1));
	if (table->n_meals != -1)
		table->full_sem = sem_open("/full_sem", O_CREAT, 0644, 0);
	else
		table->full_sem = NULL;
	if (table->forks_sem == SEM_FAILED || table->print_sem == SEM_FAILED
		|| table->meal_sem == SEM_FAILED || table->room_sem == SEM_FAILED
		|| (table->n_meals != -1 && table->full_sem == SEM_FAILED))
		return (false);
	table->pids = malloc(sizeof(pid_t) * table->n_philos);
	table->philos = malloc(sizeof(t_philo) * table->n_philos);
	if (!table->pids || !table->philos)
		return (false);
	i = 0;
	while (i < table->n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].full = 0;
		i++;
	}
	return (true);
}
