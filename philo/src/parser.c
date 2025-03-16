/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:56:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 14:20:45 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define ARGS "number_of_philosophers time_to_die time_to_eat time_to_sleep"
#define OPT_ARG "[number_of_times_each_philosopher_must_eat]"

static unsigned int	ft_atoui_checker(const char *str, int *error)
{
	unsigned int	result;

	if (*error)
		return (0);
	if (!str)
	{
		*error = 1;
		return (0);
	}
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	str += *str == '+';
	while (*error == 0 && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str++ - '0');
		*error = (*str >= '0' && *str <= '9')
			&& ((result > UINT_MAX / 10)
				|| (result == UINT_MAX / 10
					&& *str - '0' > (int)(UINT_MAX % 10)));
	}
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	*error += *str != '\0';
	return (result);
}

static int	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s %s %s\n", argv[0], ARGS, OPT_ARG);
		return (0);
	}
	return (1);
}

static int	fill_table(t_table *table, int argc, char **argv)
{
	int	error;

	error = 0;
	table->n_philos = ft_atoui_checker(argv[1], &error);
	table->t_die = ft_atoui_checker(argv[2], &error);
	table->t_eat = ft_atoui_checker(argv[3], &error);
	table->t_sleep = ft_atoui_checker(argv[4], &error);
	if (argc == 6)
		table->n_meals = (long)ft_atoui_checker(argv[5], &error);
	else
		table->n_meals = -1;
	if (error)
	{
		printf("Error: Parameters must be positive integers\n");
		return (0);
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_table *table)
{
	if (!validate_args(argc, argv))
		return (1);
	if (!fill_table(table, argc, argv))
		return (1);
	return (0);
}
