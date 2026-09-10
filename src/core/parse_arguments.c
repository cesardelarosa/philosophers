/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:06:04 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 09:30:56 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdio.h>
#include <limits.h>

#define ARGS "number_of_philosophers time_to_die time_to_eat time_to_sleep"
#define OPT_ARG "[number_of_times_each_philosopher_must_eat]"

static unsigned int	ft_atoui(const char *str, int *error)
{
	unsigned int	res;

	res = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+')
		str++;
	if (*str < '0' || *str > '9')
	{
		*error |= 1;
		return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > INT_MAX)
		{
			*error |= 2;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
		*error |= 1;
	return (res);
}

static void	handle_error(int error)
{
	if (error & 1)
		printf("Arguments must be non negative numbers\n");
	if (error & 2)
		printf("Arguments must not exceed MAX_INT\n");
}

bool	parse_arguments(int argc, char **argv, t_table *table)
{
	int	error;

	error = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s %s %s\n", argv[0], ARGS, OPT_ARG);
		return (false);
	}
	table->n_philos = ft_atoui(argv[1], &error);
	table->t_die = 1000 * (uint64_t)ft_atoui(argv[2], &error);
	table->t_eat = 1000 * (uint64_t)ft_atoui(argv[3], &error);
	table->t_sleep = 1000 * (uint64_t)ft_atoui(argv[4], &error);
	if (argc == 6)
		table->n_meals = (long)ft_atoui(argv[5], &error);
	else
		table->n_meals = -1;
	if (error)
	{
		handle_error(error);
		return (false);
	}
	return (true);
}
