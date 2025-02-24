/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:55:17 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/24 17:59:13 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "simulation.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

static void	cleanup_partial(t_data *data, int fork_count)
{
	int	i;

	i = 0;
	while (i < fork_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
	free(data->philos);
	data->philos = NULL;
	pthread_mutex_destroy(&data->print_mutex);
}

void	*monitor_philosophers(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!data->stop)
	{
		i = 0;
		while (i < data->params.n_philos && !data->stop)
		{
			if (get_time_in_ms()
				- data->philos[i].last_meal > data->params.t_die)
			{
				to_die(&data->philos[i]);
				break ;
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

static void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->data->stop && (philo->data->params.n_meals == -1
			|| philo->meals_eaten < philo->data->params.n_meals))
	{
		to_think(philo);
		to_eat(philo);
		to_sleep(philo);
	}
	return (NULL);
}

int	init_simulation(t_data *data)
{
	int	i;

	data->start_time = get_time_in_ms();
	data->stop = 0;
	data->philos = malloc(sizeof(t_philosopher) * data->params.n_philos);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->params.n_philos);
	if (!data->forks)
	{
		free(data->philos);
		return (1);
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		free(data->forks);
		free(data->philos);
		return (1);
	}
	i = 0;
	while (i < data->params.n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			cleanup_partial(data, i);
			return (1);
		}
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

int	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->params.n_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine,
				&data->philos[i]) != 0)
		{
			data->stop = 1;
			while (i > 0)
			{
				i--;
				pthread_join(data->philos[i].thread, NULL);
			}
			return (1);
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_philosophers, data) != 0)
	{
		data->stop = 1;
		i = 0;
		while (i < data->params.n_philos)
		{
			pthread_join(data->philos[i].thread, NULL);
			i++;
		}
		return (1);
	}
	i = 0;
	while (i < data->params.n_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	return (0);
}

void	cleanup_simulation(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->params.n_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->print_mutex);
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}
