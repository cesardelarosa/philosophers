/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:54:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 11:17:27 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_forks(t_table *table)
{
	unsigned int	i;

	if (!table->forks)
		return ;
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_destroy(&table->forks[i].mtx);
		i++;
	}
	free(table->forks);
	table->forks = NULL;
}

void	destroy_philos(t_table *table, unsigned int n_created)
{
	if (!table->philos)
		return ;
	while (n_created-- > 0)
	{
		pthread_mutex_destroy(&table->philos[n_created].meal_mtx);
		pthread_mutex_destroy(&table->philos[n_created].state_mtx);
	}
	free(table->philos);
	table->philos = NULL;
}

void	clean_resources(t_table *table)
{
	if (!table)
		return ;
	if (table->print_mtx_init)
		pthread_mutex_destroy(&table->print_mtx);
	if (table->stop_mtx_init)
		pthread_mutex_destroy(&table->stop_mtx);
	destroy_forks(table);
	destroy_philos(table, table->n_philos);
}
