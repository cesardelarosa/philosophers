/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:39 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 21:05:47 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_utils.h"
#include <stdbool.h>

bool	think(t_philo *philo)
{
	print_status(philo, "is thinking");
	return (true);
}
