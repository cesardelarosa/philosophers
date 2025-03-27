/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:32 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 08:51:15 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include <unistd.h>
#include <stdbool.h>

bool	to_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->table->t_sleep);
	return (true);
}
