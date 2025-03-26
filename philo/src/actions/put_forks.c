/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 20:19:19 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"

bool	put_forks(t_philo *philo)
{
	lock_safe_mutex(&philo->first_fork->mtx);
	lock_safe_mutex(&philo->second_fork->mtx);
	philo->first_fork->taken = 0;
	philo->second_fork->taken = 0;
	unlock_safe_mutex(&philo->second_fork->mtx);
	unlock_safe_mutex(&philo->first_fork->mtx);
	return (true);
}
