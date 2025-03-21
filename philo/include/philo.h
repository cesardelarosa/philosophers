/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 11:26:38 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structs.h"

uint64_t				get_time(void);
bool					smart_sleep(t_philo *philo, uint64_t us);
uint64_t				read_meal_time(t_philo *philo);
bool					check_stop(t_table *table);
bool					check_death(t_philo *philo);
void					print_state(t_philo *philo, const char *state);

#endif