/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:45:14 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 10:52:31 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handler(const char *msg, t_table *table)
{
	if (msg)
		printf("\033[1;31mError: %s\033[0m\n", msg);
	if (table)
		clean_resources(table);
	return (1);
}
