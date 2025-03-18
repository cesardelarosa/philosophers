/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:17:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 15:49:49 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "structs.h"

bool	parse_arguments(int argc, char **argv, t_table *table);
bool	init_simulation(t_table *table);
bool	run_simulation(t_table *table);
void	clean_resources(t_table *table);
int		error_handler(const char *msg, t_table *table);

#endif
