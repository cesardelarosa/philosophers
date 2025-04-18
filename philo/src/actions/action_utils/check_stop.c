/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:02:36 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/18 10:45:58 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

bool	check_stop(t_table *table)
{
	bool	stop_state;

	lock_safe_mutex(&table->stop_mtx);
	stop_state = table->stop;
	unlock_safe_mutex(&table->stop_mtx);
	return (stop_state);
}
