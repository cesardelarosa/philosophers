/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:54:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/26 16:01:10 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_forks(t_table *table)
{
	int	i;

	if (!table->forks)
		return ;
	i = -1;
	while (++i < table->n_philos)
		pthread_mutex_destroy(&table->forks[i].mtx);
	free(table->forks);
	table->forks = NULL;
}

static void	destroy_philos(t_table *table)
{
	int	i;

	if (!table->philos)
		return ;
	i = -1;
	while (++i < table->n_philos)
	{
		pthread_mutex_destroy(&table->philos[i].meal_mtx);
		pthread_mutex_destroy(&table->philos[i].state_mtx);
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
	destroy_philos(table);
}
