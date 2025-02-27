/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:10:49 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/27 13:17:27 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philosopher(t_philo *philo, t_table *table)
{
	int				ret;

	ret = 0;
	if ((unsigned int)(get_time() - read_meal_time(philo)) >= table->t_die)
	{
		print_state(philo, "died");
		set_stop(table, true);
		ret = -1;
	}
	else if (table->n_meals > 0 && read_meals_eaten(philo) >= table->n_meals)
		ret = 1;
	return (ret);
}

static long	check_all_philosophers(t_table *table)
{
	unsigned int	i;
	unsigned int	completed_count;
	int				ret;

	completed_count = 0;
	i = 0;
	while (i < table->n_philos && !check_stop(table))
	{
		ret = check_philosopher(&table->philos[i], table);
		if (ret == -1)
			return (-1);
		completed_count += ret == 1;
		i++;
	}
	return ((long)completed_count);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	long	completed;

	table = (t_table *)arg;
	while (!check_stop(table))
	{
		completed = check_all_philosophers(table);
		if (completed == -1)
			break ;
		if (table->n_meals > 0 && (unsigned int)completed == table->n_philos)
		{
			set_stop(table, true);
			pthread_mutex_lock(&table->print_mtx);
			printf("All philosophers are full\n");
			pthread_mutex_unlock(&table->print_mtx);
			break ;
		}
		precise_usleep(1);
	}
	return (NULL);
}
