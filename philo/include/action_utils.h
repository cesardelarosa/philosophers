/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 17:58:53 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_UTILS_H
# define ACTION_UTILS_H

# include "structs.h"

bool				philo_sleep(t_philo *philo, unsigned int ms);
bool				print_state(t_philo *philo, const char *state);
bool				check_philo(t_philo *philo);

#endif
