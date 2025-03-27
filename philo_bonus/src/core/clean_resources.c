/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 22:55:37 by cesi             ###   ########.fr       */
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
	if (table->pids)
		free(table->pids);
	if (table->philos)
		free(table->philos);
}
