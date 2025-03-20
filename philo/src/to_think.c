/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:39 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/20 22:59:40 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	to_think(t_philo *philo)
{
	if (check_stop(philo->table))
		return (false);
	print_state(philo, "is thinking");
	return (true);
}
