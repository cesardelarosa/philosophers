/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:31:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/26 17:16:22 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	to_think(t_philo *philo, unsigned int t_think)
{
	if (check_stop(philo->table))
		return ;
	print_state(philo, "is thinking");
	if (t_think > 0)
		precise_usleep(t_think);
}
