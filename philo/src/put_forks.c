/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 09:57:58 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	put_forks(t_philo *philo)
{
	if (check_stop(philo->table))
		return (false);
	pthread_mutex_lock(&philo->first_fork->mtx);
	pthread_mutex_lock(&philo->second_fork->mtx);
	philo->first_fork->taken = 0;
	philo->second_fork->taken = 0;
	pthread_mutex_unlock(&philo->second_fork->mtx);
	pthread_mutex_unlock(&philo->first_fork->mtx);
	return (true);
}
