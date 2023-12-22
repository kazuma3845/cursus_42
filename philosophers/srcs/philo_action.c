/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:20:18 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/22 13:16:29 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->info->philo_death == 0)
	{
	pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
	print_msg("has taken a fork", philo);
	print_msg("is eating", philo);
	philo->t_lastmeal = get_time() - philo->info->time_start;
	philo->meals_eaten++;
	ft_sleep(philo->info->time_eat, philo->info);
	pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	}
}

void philo_sleep(t_philo *philo)
{
	if (philo->info->philo_death == 0)
	{
		print_msg("is sleeping", philo);
		ft_sleep(philo->info->time_sleep, philo->info);
	}
}

void philo_think(t_philo *philo)
{
	if (philo->info->philo_death == 0)
		print_msg("is thinking", philo);
}

void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->checker);
	if ((get_time() - philo->info->time_start) - philo->t_lastmeal >= philo->info->time_die)
	{
		print_msg("dead", philo);
		philo->info->philo_death = 1;
	}
	pthread_mutex_unlock(&philo->info->checker);
}
