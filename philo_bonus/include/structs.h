/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 22:59:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/27 09:43:54 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include <semaphore.h>
# include <sys/types.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	unsigned int	meals_eaten;
	uint64_t		last_meal;
	int				full;
	t_table			*table;
}				t_philo;

struct s_table
{
	unsigned int	n_philos;
	uint64_t		t_die;
	uint64_t		t_eat;
	uint64_t		t_sleep;
	long			n_meals;
	uint64_t		start_time;
	t_philo			*philos;
	pid_t			*pids;
	sem_t			*forks_sem;
	sem_t			*print_sem;
	sem_t			*meal_sem;
	sem_t			*full_sem;
};

#endif
