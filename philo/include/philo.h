/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 14:17:21 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define PHILO_MAX 200
# define MS 1000

# include "structs.h"

void				destroy_philos(t_table *table, unsigned int n_created);
void				destroy_forks(t_table *table, unsigned int n_created);
int					error_handler(const char *msg, t_table *table);

uint64_t			get_time(void);
bool				philo_sleep(t_philo *philo, unsigned int ms);
void				precise_usleep(unsigned int ms);

void				print_state(t_philo *philo, const char *state);
bool				check_stop(t_table *table);
void				set_stop(t_table *table, bool value);

void				update_meal_time(t_philo *philo);
uint64_t			read_meal_time(t_philo *philo);
unsigned int		read_meals_eaten(t_philo *philo);
void				add_meal(t_philo *philo);

void				to_eat(t_philo *philo);
void				to_sleep(t_philo *philo);
void				to_think(t_philo *philo);

#endif
