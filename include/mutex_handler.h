/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:41:36 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/25 17:53:50 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_HANDLER_H
# define MUTEX_HANDLER_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_safe_mutex
{
	pthread_mutex_t	mtx;
	bool			init;
}				t_safe_mutex;

bool	init_safe_mutex(t_safe_mutex *smx);
bool	lock_safe_mutex(t_safe_mutex *smx);
bool	unlock_safe_mutex(t_safe_mutex *smx);
bool	destroy_safe_mutex(t_safe_mutex *smx);

#endif
