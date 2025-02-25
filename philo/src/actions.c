/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:55:53 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/24 19:55:55 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static void	log_action(t_philosopher *philo, const char *action)
{
	long	timestamp;

	if (philo->table->stop)
		return ;
	timestamp = get_time_in_ms() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

static void	take_fork(t_philosopher *philo, int fork_index)
{
	pthread_mutex_lock(&philo->table->forks[fork_index]);
	log_action(philo, "has taken a fork");
}

void	to_eat(t_philosopher *philo)
{
	if (philo->table->n_philosophers == 1)
	{
		take_fork(philo, 0);
		usleep((philo->table->t_die + 1) * 1000);
		pthread_mutex_unlock(&philo->table->forks[0]);
		return ;
	}
	else if (philo->id % 2 == 0)
	{
		take_fork(philo, philo->id % philo->table->n_philosophers);
		take_fork(philo, philo->id - 1);
	}
	else
	{
		take_fork(philo, philo->id - 1);
		take_fork(philo, philo->id % philo->table->n_philosophers);
	}
	log_action(philo, "is eating");
	usleep(philo->table->t_eat * 1000);
	philo->last_meal = get_time_in_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->table->forks[philo->id
		% philo->table->n_philosophers]);
}

void	to_sleep(t_philosopher *philo)
{
	log_action(philo, "is sleeping");
	usleep(philo->table->t_sleep * 1000);
}

void	to_think(t_philosopher *philo)
{
	log_action(philo, "is thinking");
}
