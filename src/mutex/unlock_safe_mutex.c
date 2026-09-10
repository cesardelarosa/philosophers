/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_safe_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:42:16 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 10:27:18 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex_handler.h"

bool	unlock_safe_mutex(t_safe_mutex *smx)
{
	return (smx->init && (pthread_mutex_unlock(&smx->mtx) == 0));
}
