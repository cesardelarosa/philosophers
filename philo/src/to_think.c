/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:47:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/18 19:22:46 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"

bool	to_think(t_philo *philo)
{
	if (!check_philo(philo))
		return (false);
	print_state(philo, "is thinking");
	return (true);
}
