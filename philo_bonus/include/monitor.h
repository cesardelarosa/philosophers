/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:54:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 11:45:04 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include "structs.h"

typedef struct s_monitor_arg
{
	t_table			*table;
	volatile int	*all_full;
}					t_monitor_arg;

#endif
