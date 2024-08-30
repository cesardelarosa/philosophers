/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:08:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/30 09:19:24 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int				num_philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	if (argc != 2)
	{
		printf("Usage: ./philo number_of_philosophers\n");
		return (1);
	}
	num_philos = atoi(argv[1]);
	if (init_resources(&threads, &forks, &philos, num_philos) != 0)
		return (1);
	create_philosophers(threads, philos, forks, num_philos);
	join_philosophers(threads, num_philos);
	cleanup_resources(threads, forks, philos, num_philos);
	return (0);
}
