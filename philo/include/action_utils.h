/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 10:31:44 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_UTILS_H
# define ACTION_UTILS_H

# include "structs.h"

bool					smart_sleep(t_philo *philo, uint64_t us);
bool					check_stop(t_table *table);
bool					print_state(t_philo *philo, const char *state);

#endif
