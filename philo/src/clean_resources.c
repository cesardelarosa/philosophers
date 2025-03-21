/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 11:32:09 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	clean_resources(t_table *table)
{
	unsigned int	i;

	if (table->forks)
	{
		free(table->forks);
		table->forks = NULL;
	}
	if (table->philos)
	{
		i = 0;
		while (i < table->n_philos)
		{
			pthread_mutex_destroy(&table->philos[i].meal_mtx);
			i++;
		}
		free(table->philos);
		table->philos = NULL;
	}
	pthread_mutex_destroy(&table->print_mtx);
	pthread_mutex_destroy(&table->stop_mtx);
	pthread_mutex_destroy(&table->forks_avail_mtx);
	pthread_mutex_destroy(&table->full_mtx);
}
