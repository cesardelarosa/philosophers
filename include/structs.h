/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 13:50:05 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "mutex_handler.h"
# include <stdint.h>

typedef struct s_fork
{
	int					id;
	int					taken;
	int					stamp;
	t_safe_mutex		mtx;
}	t_fork;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	uint64_t			last_meal;
	t_fork				*first_fork;
	t_fork				*second_fork;
	unsigned int		meals_eaten;
	bool				full;
	struct s_table		*table;
}	t_philo;

typedef struct s_table
{
	unsigned int		n_philos;
	uint64_t			t_die;
	uint64_t			t_eat;
	uint64_t			t_sleep;
	long				n_meals;
	unsigned int		full_count;
	bool				stop;
	uint64_t			start_time;
	t_philo				*philos;
	t_fork				*forks;
	t_safe_mutex		print_mtx;
	t_safe_mutex		stop_mtx;
	t_safe_mutex		full_mtx;
}	t_table;

#endif
