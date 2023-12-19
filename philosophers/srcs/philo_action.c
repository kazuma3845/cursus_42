/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:20:18 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/19 14:55:51 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->fork_left);
	print_msg("has taken a fork", philo);
	if (philo->info->nbr_philo == 1)
	{
		ft_sleep(philo->info->time_die + 1, philo);
		return ;
	}
	pthread_mutex_lock(philo->fork_right);
	print_msg("has taken a fork", philo);
}

void	philo_eat(t_philo *philo)
{
	print_msg("is eating", philo);
	pthread_mutex_lock(&philo->info->m_eat);
	philo->last_eat = get_time();
	philo->food_count++;
	pthread_mutex_unlock(&philo->info->m_eat);
	ft_sleep(philo->info->time_eat, philo);
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	print_msg("is sleeping", philo);
	ft_sleep(philo->info->time_sleep, philo);
	print_msg("is thinking", philo);
}

int	philo_dead(t_philo *philo, int death)
{
	pthread_mutex_lock(&philo->info->dead);
	if (death)
		philo->info->philo_death = 1;
	if (philo->info->philo_death == 1)
	{
		pthread_mutex_unlock(&philo->info->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->dead);
	return (0);
}
