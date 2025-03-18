/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 13:14:01 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "structs.h"

bool				to_eat(t_philo *philo);
bool				to_sleep(t_philo *philo);
bool				to_think(t_philo *philo);

#endif
