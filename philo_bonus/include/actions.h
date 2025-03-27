/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 08:26:44 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "structs.h"
# include <stdbool.h>

bool					think(t_philo *philo);
bool					take_forks(t_philo *philo);
bool					eat(t_philo *philo);
bool					put_forks(t_philo *philo);
bool					to_sleep(t_philo *philo);

#endif
