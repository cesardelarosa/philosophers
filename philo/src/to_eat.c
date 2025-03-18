/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:10:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 19:47:49 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include "philo.h"

static void	update_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_mtx);
}

static void	add_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mtx);
	philo->meals_eaten++;
	if (philo->table->n_meals != -1
		&& philo->meals_eaten == (unsigned int)philo->table->n_meals
		&& !philo->full)
	{
		philo->full = true;
		pthread_mutex_lock(&philo->table->full_mtx);
		if (++philo->table->full_count == philo->table->n_philos)
			set_stop(philo->table, true);
		pthread_mutex_unlock(&philo->table->full_mtx);
	}
	pthread_mutex_unlock(&philo->meal_mtx);
}

static void	assign_forks(t_philo *philo, t_fork *forks[2])
{
	if (philo->left_fork->id < philo->right_fork->id)
	{
		forks[0] = philo->left_fork;
		forks[1] = philo->right_fork;
	}
	else
	{
		forks[0] = philo->right_fork;
		forks[1] = philo->left_fork;
	}
}

bool	to_eat(t_philo *philo)
{
	t_fork	*forks[2];
	bool	r;

	if (!check_philo(philo))
		return (false);
	if (philo->left_fork->id == philo->right_fork->id)
	{
		pthread_mutex_lock(&philo->right_fork->mtx);
		print_state(philo, "has taken a fork");
		philo_sleep(philo, philo->table->t_die + 1);
		pthread_mutex_unlock(&philo->right_fork->mtx);
		return (false);
	}
	assign_forks(philo, forks);
	pthread_mutex_lock(&forks[0]->mtx);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(&forks[1]->mtx);
	print_state(philo, "has taken a fork");
	update_meal_time(philo);
	print_state(philo, "is eating");
	add_meal(philo);
	r = philo_sleep(philo, philo->table->t_eat);
	pthread_mutex_unlock(&forks[1]->mtx);
	pthread_mutex_unlock(&forks[0]->mtx);
	return (r);
}
