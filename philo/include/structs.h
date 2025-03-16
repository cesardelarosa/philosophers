/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:16:18 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/16 18:29:39 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "common.h"

typedef struct s_fork
{
	unsigned int	id;
	pthread_mutex_t	mtx;
}					t_fork;

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	uint64_t		last_meal;
	bool			full;
	unsigned int	meals_eaten;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	meal_mtx;
	pthread_mutex_t	state_mtx;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	unsigned int	n_philos;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	long			n_meals;
	uint64_t		start_time;
	bool			stop;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	stop_mtx;
	bool			print_mtx_init;
	bool			stop_mtx_init;
	unsigned int	full_count;
	pthread_mutex_t	full_mtx;
	bool			full_mtx_init;
}					t_table;

#endif
