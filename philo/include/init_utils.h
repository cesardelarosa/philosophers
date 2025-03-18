/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 14:38:31 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_UTILS_H
# define INIT_UTILS_H

# include "structs.h"

# define PHILO_MAX 200

void				destroy_philos(t_table *table, unsigned int n_created);
void				destroy_forks(t_table *table, unsigned int n_created);

#endif
