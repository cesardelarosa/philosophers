/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 09:21:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/30 09:24:49 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

/*
typedef struct s_args
{
        int     n;
        int     t_die;
        int     t_eat;
        int     t_sleep;
        int     max_eat;
}       t_args;

typedef struct s_philo
{
        int     n;
        int     state;
        int     eats;
}       t_philo;

typedef struct s_table
{
        t_philo *philo;
        int             *forks;
}       t_table;
*/

int		init_resources(pthread_t **threads, pthread_mutex_t **forks, t_philo **philos, int num_philos);
void	create_philosophers(pthread_t *threads, t_philo *philos, pthread_mutex_t *forks, int num_philos);
void	join_philosophers(pthread_t *threads, int num_philos);
void	cleanup_resources(pthread_t *threads, pthread_mutex_t *forks, t_philo *philos, int num_philos);
void	*philosopher(void *arg);

#endif
