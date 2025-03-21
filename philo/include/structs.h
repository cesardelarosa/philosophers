/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/21 22:57:15 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "common.h"

typedef struct s_fork
{
	int					id;
	int					taken;
	pthread_mutex_t		mtx;
}	t_fork;

typedef struct s_philo
{
	int					id;
	unsigned int		meals_eaten;
	uint64_t			last_meal;
	int					first_fork;
	int					second_fork;
	bool				full;
	pthread_t			thread;
	pthread_mutex_t		meal_mtx;
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
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		stop_mtx;
	pthread_mutex_t		full_mtx;
}	t_table;

#endif
