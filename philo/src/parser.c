/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:11:50 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/24 17:34:48 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "philo.h"

static int	ft_atoi_checker(const char *str, int *error)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		*error = 1;
		return (0);
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return ((int)result);
}

int	parse_args(int argc, char **argv, t_params *params)
{
	int	error;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: %s number_of_philosophers time_to_die time_to_eat "
			"time_to_sleep [number_of_times_each_philosopher_must_eat]\n",
			argv[0]);
		return (1);
	}
	error = 0;
	params->n_philos = ft_atoi_checker(argv[1], &error);
	params->t_die = ft_atoi_checker(argv[2], &error);
	params->t_eat = ft_atoi_checker(argv[3], &error);
	params->t_sleep = ft_atoi_checker(argv[4], &error);
	if (argc == 6)
		params->n_meals = ft_atoi_checker(argv[5], &error);
	else
		params->n_meals = -1;
	if (error == 1)
	{
		printf("Params must be positive integers.\n");
		return (1);
	}
	return (0);
}
