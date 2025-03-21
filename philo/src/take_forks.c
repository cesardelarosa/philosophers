/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 11:25:22 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	handle_single_philo(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->forks_avail_mtx);
	if (table->forks[0].taken == 0)
	{
		table->forks[0].taken = 1;
		pthread_mutex_unlock(&table->forks_avail_mtx);
		print_state(philo, "has taken a fork");
	}
	else
		pthread_mutex_unlock(&table->forks_avail_mtx);
	smart_sleep(philo, table->t_die);
	pthread_mutex_lock(&table->forks_avail_mtx);
	table->forks[0].taken = 0;
	pthread_mutex_unlock(&table->forks_avail_mtx);
	check_death(philo);
	return (false);
}

static uint64_t	calc_wait_time(t_philo *philo)
{
	uint64_t		current;
	uint64_t		elapsed;
	uint64_t		remaining;
	uint64_t		wait_time;
	t_table			*table;

	table = philo->table;
	current = get_time();
	elapsed = current - read_meal_time(philo);
	if (table->t_die <= elapsed)
		return (0);
	remaining = table->t_die - elapsed;
	if (remaining >= 1000)
		wait_time = remaining / 50;
	else if (remaining >= 100)
		wait_time = remaining / 100;
	else
		wait_time = (remaining / 10 + ((100 - remaining) * remaining) / 1000);
	if (wait_time < 1)
		wait_time = 1;
	if (wait_time > remaining)
		wait_time = remaining;
	return (wait_time);
}

bool	take_forks(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_stop(table))
		return (false);
	if (table->n_philos == 1)
		return (handle_single_philo(philo));
	while (smart_sleep(philo, calc_wait_time(philo)))
	{
		pthread_mutex_lock(&table->forks_avail_mtx);
		if (table->forks[philo->left_index].taken == 0
			&& table->forks[philo->right_index].taken == 0)
		{
			table->forks[philo->left_index].taken = 1;
			table->forks[philo->right_index].taken = 1;
			pthread_mutex_unlock(&table->forks_avail_mtx);
			print_state(philo, "has taken a fork");
			print_state(philo, "has taken a fork");
			return (true);
		}
		pthread_mutex_unlock(&table->forks_avail_mtx);
	}
	return (false);
}
