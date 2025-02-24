/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:00:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/24 17:54:15 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void	log_action(t_philosopher *philo, const char *action)
{
	long	timestamp;

	if (philo->data->stop)
		return ;
	timestamp = get_time_in_ms() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("%ld %d %s\n", timestamp, philo->id, action);
	if (*action != 'd')
		pthread_mutex_unlock(&philo->data->print_mutex);
}

static void	take_fork(t_philosopher *philo, int fork_index)
{
	pthread_mutex_lock(&philo->data->forks[fork_index]);
	log_action(philo, "has taken a fork");
}

void	to_eat(t_philosopher *philo)
{
	if (philo->data->params.n_philos == 1)
	{
		take_fork(philo, 0);
		usleep((philo->data->params.t_die + 1) * 1000);
		pthread_mutex_unlock(&philo->data->forks[0]);
		return ;
	}
	else if (philo->id % 2 == 0)
	{
		take_fork(philo, philo->id % philo->data->params.n_philos);
		take_fork(philo, philo->id - 1);
	}
	else
	{
		take_fork(philo, philo->id - 1);
		take_fork(philo, philo->id % philo->data->params.n_philos);
	}
	log_action(philo, "is eating");
	usleep(philo->data->params.t_eat * 1000);
	philo->last_meal = get_time_in_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->id
		% philo->data->params.n_philos]);
}

void	to_sleep(t_philosopher *philo)
{
	log_action(philo, "is sleeping");
	usleep(philo->data->params.t_sleep * 1000);
}

void	to_think(t_philosopher *philo)
{
	log_action(philo, "is thinking");
}

void	to_die(t_philosopher *philo)
{
	log_action(philo, "died");
	philo->data->stop = 1;
	pthread_exit(NULL);
}
