/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:21:04 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 14:21:35 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (parse_arguments(argc, argv, &table))
		return (error_handler("Invalid arguments", &table));
	if (init_simulation(&table))
		return (error_handler("Simulation init failed", &table));
	if (run_simulation(&table))
		return (error_handler("Runtime error", &table));
	clean_resources(&table);
	return (0);
}
