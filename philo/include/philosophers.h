/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:17:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 14:22:35 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "structs.h"

int					parse_arguments(int argc, char **argv, t_table *table);
int					init_simulation(t_table *table);
int					run_simulation(t_table *table);
void				clean_resources(t_table *table);
int					error_handler(const char *msg, t_table *table);

#endif
