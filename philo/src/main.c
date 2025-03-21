/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:05:51 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 11:26:49 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (!parse_arguments(argc, argv, &table))
	{
		write(2, "Invalid arguments\n", 18);
		return (1);
	}
	if (!init_simulation(&table))
	{
		write(2, "Simulation initialization failed\n", 34);
		clean_resources(&table);
		return (1);
	}
	if (run_simulation(&table) != 0)
	{
		write(2, "Simulation encountered an error\n", 33);
		clean_resources(&table);
		return (1);
	}
	clean_resources(&table);
	return (0);
}
