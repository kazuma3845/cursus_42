/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:34:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/14 17:14:56 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->general->philosopher_dead == 0)
	{
		if (philo_dead(philo))
			return (0);
		philo_fork(philo);
		if (philo_dead(philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (0);
		}
		philo_eat(philo);
		if (philo_dead(philo))
			return (0);
		philo_sleep(philo);
		if (philo_dead(philo))
			return (0);
		philo_think(philo);
	}
	return (0);
}

void	beggin(t_general *prog)
{
	int	i;

	i = -1;
	prog->starting_time = get_time();
	while (++i < prog->number_of_philosophers)
		pthread_create(&prog->philosophers[i].thread_id, NULL, &routine, (void *)&prog->philosophers[i]);
	i = -1;
	while (++i < prog->number_of_philosophers)
		pthread_join(prog->philosophers[i].thread_id, NULL);
}

int last_food(t_philo *philo)
{
	if (get_time() - philo->general->starting_time > philo->time_to_die)
	{
		philo->general->philosopher_dead = 1;
		printf("%d %d died\n", get_time() - philo->general->starting_time, philo->id);
		return (0);
	}
	else
		return (1);
}

int check_if_dead(t_general *prog)
{
	int i;

	i = -1;
	while (++i != prog->number_of_philosophers)
	{
		if (last_food(&prog->philosophers[i]) == 0)
			return (0);
	}
	return (1);
}

void *algo(t_general *prog)
{
	while (1)
	{
		pthread_mutex_lock(&prog->mutex);
		if (check_if_dead(prog) == 0)
		{
			usleep(100);
			pthread_mutex_unlock(&prog->mutex);
			return (0);
		}
		pthread_mutex_unlock(&prog->mutex);
		usleep(200);
	}
}
