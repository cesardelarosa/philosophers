/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 11:20:46 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdlib.h>

void	clean_resources(t_table *table)
{
	unsigned int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->n_philos)
		{
			destroy_safe_mutex(&table->forks[i].mtx);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
	}
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
	destroy_safe_mutex(&table->print_mtx);
	destroy_safe_mutex(&table->stop_mtx);
	destroy_safe_mutex(&table->full_mtx);
}
