/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:54:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 18:30:13 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_table *table, unsigned int n_created)
{
	if (!table->forks)
		return ;
	while (n_created-- > 0)
		pthread_mutex_destroy(&table->forks[n_created].mtx);
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
	if (table->full_mtx_init)
		pthread_mutex_destroy(&table->full_mtx);
	destroy_forks(table, table->n_philos);
	destroy_philos(table, table->n_philos);
}

int	error_handler(const char *msg, t_table *table)
{
	if (msg)
		printf("\033[1;31mError: %s\033[0m\n", msg);
	if (table)
		clean_resources(table);
	return (1);
}
