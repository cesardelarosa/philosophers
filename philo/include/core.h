/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 12:06:56 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "structs.h"

bool	parse_arguments(int argc, char **argv, t_table *table);
bool	init_simulation(t_table *table);
bool	run_simulation(t_table *table);
void	clean_resources(t_table *table);
int		print_error(char *str);

#endif
