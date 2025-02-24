/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:50 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/24 10:58:24 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (parse_args(argc, argv, &(data.params)))
		return (1);
	if (init_simulation(&data))
	{
		printf("Error initializing simulation\n");
		return (1);
	}
	if (start_simulation(&data))
	{
		printf("Error initializing simulation\n");
		cleanup_simulation(&data);
		return (1);
	}
	cleanup_simulation(&data);
	return (0);
}
