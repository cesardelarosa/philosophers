/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:19 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 14:13:26 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_ordered_forks(t_philo *philo, t_fork **first, t_fork **second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
	else
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
}

static void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx);
	print_state(philo, "has taken a fork");
}

void	to_eat(t_philo *philo)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->table->n_philos == 1)
	{
		take_fork(philo, philo->right_fork);
		precise_usleep(philo->table->t_die + 1);
		pthread_mutex_unlock(&philo->right_fork->mtx);
		return ;
	}
	get_ordered_forks(philo, &first, &second);
	take_fork(philo, first);
	take_fork(philo, second);
	print_state(philo, "is eating");
	update_meal_time(philo);
	precise_usleep(philo->table->t_eat);
	add_meal(philo);
	pthread_mutex_unlock(&second->mtx);
	pthread_mutex_unlock(&first->mtx);
}
