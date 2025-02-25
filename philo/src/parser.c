/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:56:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/25 11:15:07 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "philo.h"

static int	ft_atoi_checker(const char *str, int *error)
{
	long	result;

	if (!str)
	{
		*error = 1;
		return (0);
	}
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+')
		str++;
	while (result <= (long)INT_MAX && *str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	*error += result > (long)INT_MAX || result == 0 || *str != '\0';
	return ((int)result);
}

int	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s %s %s\n", argv[0], ARGS, OPT_ARG);
		return (0);
	}
	return (1);
}

int	fill_table(t_table *table, char **argv)
{
	int	error;

	error = 0;
	table->n_philosophers = ft_atoi_checker(argv[1], &error);
	table->t_die = ft_atoi_checker(argv[2], &error);
	table->t_eat = ft_atoi_checker(argv[3], &error);
	table->t_sleep = ft_atoi_checker(argv[4], &error);
	if (argv[5] != NULL)
		table->n_meals = ft_atoi_checker(argv[5], &error);
	else
		table->n_meals = -1;
	if (error)
	{
		printf("Params must be positive integers.\n");
		return (0);
	}
	return (1);
}

t_table	*parser(int argc, char **argv)
{
	t_table	*table;

	if (!validate_args(argc, argv))
		return (NULL);
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	if (!fill_table(table, argv))
	{
		free(table);
		return (NULL);
	}
	return (table);
}
