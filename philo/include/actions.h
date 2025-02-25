/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:06:35 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 10:46:09 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "philo.h"

void	to_eat(t_philosopher *philo);
void	to_sleep(t_philosopher *philo);
void	to_think(t_philosopher *philo);
long	get_time_in_ms(void);

#endif
