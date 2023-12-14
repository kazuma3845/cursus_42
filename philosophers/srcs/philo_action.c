/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:20:18 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/14 17:04:39 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (!philo_dead(philo))
		print_msg("has taken a fork", philo);
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
			return (pthread_mutex_unlock(philo->right_fork), 1);
		if (!philo_dead(philo))
			print_msg("has taken a fork", philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
			return (pthread_mutex_unlock(philo->left_fork), 1);
		if (!philo_dead(philo))
			print_msg("has taken a fork", philo);
	}
	return (0);
}

void philo_eat(t_philo *philo)
{
	print_msg("is eating", philo);
	pthread_mutex_lock(&philo->general->mutex);
	philo->last_meal = get_time() - philo->general->starting_time;
	philo->time_to_die = philo->last_meal + philo->general->time_to_die;
	pthread_mutex_unlock(&philo->general->mutex);
	ft_sleep(philo->general->time_to_eat, philo);
	pthread_mutex_lock(&philo->general->mutex);
	if (philo->number_of_meals != -1)
		philo->number_of_meals++;
	pthread_mutex_unlock(&philo->general->mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void philo_sleep(t_philo *philo)
{
	print_msg("is sleeping", philo);
	ft_sleep(philo->general->time_to_sleep, philo);
}

void philo_think(t_philo *philo)
{
	print_msg("is thinking", philo);
}

int philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->general->mutex);
	if (philo->general->philosopher_dead == 1)
	{
	pthread_mutex_unlock(&philo->general->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->general->mutex);
	return (0);
}
