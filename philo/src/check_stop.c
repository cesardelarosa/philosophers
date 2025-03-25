/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:36 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 20:55:48 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "mutex_handler.h"
#include <stdio.h>

bool	check_stop(t_table *table)
{
	bool	stop_state;

	lock_safe_mutex(&table->stop_mtx);
	stop_state = table->stop;
	unlock_safe_mutex(&table->stop_mtx);
	return (stop_state);
}
