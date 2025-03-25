/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:42:16 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 20:12:38 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex_handler.h"

bool	init_safe_mutex(t_safe_mutex *smx)
{
	return (smx->init = (pthread_mutex_init(&smx->mtx, NULL) == 0));
}

bool	lock_safe_mutex(t_safe_mutex *smx)
{
	return (smx->init && (pthread_mutex_lock(&smx->mtx) == 0));
}

bool	unlock_safe_mutex(t_safe_mutex *smx)
{
	return (smx->init && (pthread_mutex_unlock(&smx->mtx) == 0));
}

bool	destroy_safe_mutex(t_safe_mutex *smx)
{
	return (smx->init && (smx->init = (pthread_mutex_destroy(&smx->mtx) == 0)));
}
