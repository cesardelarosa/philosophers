/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:05:51 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 12:01:14 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (!parse_arguments(argc, argv, &table))
	{
		print_error("Invalid arguments");
		return (1);
	}
	if (!init_simulation(&table))
	{
		print_error("Simulation initialization failed");
		clean_resources(&table);
		return (1);
	}
	if (run_simulation(&table) != 0)
	{
		print_error("Simulation encountered an error");
		clean_resources(&table);
		return (1);
	}
	clean_resources(&table);
	return (0);
}
