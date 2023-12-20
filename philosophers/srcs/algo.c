/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:34:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/20 23:15:16 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_sleep(philo->info->time_die + 1);
	pthread_mutex_lock(&philo->info->m_eat);
	pthread_mutex_lock(&philo->info->m_stop);
	if (!philo_dead(philo, 0) && get_time()
		- philo->last_eat >= (long)(philo->info->time_die)
		&& philo->food_count != philo->info->nbr_eat)
	{
		pthread_mutex_unlock(&philo->info->m_eat);
		pthread_mutex_unlock(&philo->info->m_stop);
		print_msg("died", philo);
		philo_dead(philo, 1);
	}
	pthread_mutex_unlock(&philo->info->m_eat);
	pthread_mutex_unlock(&philo->info->m_stop);
	return (0);
}

void	*beggin(void *arg)
{
	pthread_t	t;
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->info->time_eat / 10);
	while (!philo_dead(philo, 0))
	{
		pthread_create(&t, NULL, routine, arg);
		philo_fork(philo);
		philo_eat(philo);
		pthread_detach(t);
		if (philo->food_count == philo->info->nbr_eat)
		{
			pthread_mutex_lock(&philo->info->m_stop);
			if (++philo->info->philo_eat == philo->info->nbr_philo)
			{
				pthread_mutex_unlock(&philo->info->m_stop);
				philo_dead(philo, 2);
			}
			pthread_mutex_unlock(&philo->info->m_stop);
			return (0);
		}
	}
	return (0);
}