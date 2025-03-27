/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 10:52:29 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>

void	clean_resources(t_table *table)
{
	sem_close(table->forks_sem);
	sem_unlink("/forks_sem");
	sem_close(table->print_sem);
	sem_unlink("/print_sem");
	sem_close(table->meal_sem);
	sem_unlink("/meal_sem");
	sem_close(table->room_sem);
	sem_unlink("/room_sem");
	if (table->n_meals != -1)
	{
		sem_close(table->full_sem);
		sem_unlink("/full_sem");
	}
	if (table->pids)
		free(table->pids);
	if (table->philos)
		free(table->philos);
}
