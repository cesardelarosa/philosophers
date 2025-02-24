/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:54:51 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/24 17:06:15 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <pthread.h>
# include "philo.h"

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	long			last_meal;
	int				meals_eaten;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_data
{
	t_params		params;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				stop;
	long			start_time;
}	t_data;

int		init_simulation(t_data *data);
int		start_simulation(t_data *data);
void	cleanup_simulation(t_data *data);

long	get_time_in_ms(void);

#endif
