/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:34:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/22 13:16:35 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
	print_msg("has taken a fork", philo);
	philo->t_lastmeal = get_time() - philo->info->time_start;
	ft_sleep(philo->info->time_die, philo->info);
	print_msg("dead", philo);
	philo->info->philo_death = 1;
	return (0);
}

void	checker(t_general *prog)
{
	int	meal_i;
	int	death_i;

	meal_i = 0;
	death_i = 0;
	while (prog->philo_death == 0)
	{
		philo_dead(&prog->philo[death_i]);
		if (prog->max_meals > 0)
		{
			while (meal_i < prog->nbr_philo)
			{
				if (prog->philo[meal_i].meals_eaten < prog->max_meals)
					break ;
				meal_i++;
			}
			if (meal_i == prog->nbr_philo)
				prog->philo_death = 1;
		}
		usleep(5000);
		if (death_i == prog->nbr_philo -1)
			death_i = -1;
		death_i++;
	}
}

void	*beggin(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1500);
	while (philo->info->philo_death == 0)
	{
		if (philo->info->max_meals > 0 && philo->meals_eaten == philo->info->max_meals)
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}

void start_prog(t_general *prog)
{
	int i;

	if (prog->nbr_philo == 1)
		one_philo(prog->philo);
	else
	{
		i = -1;
		while (++i != prog->nbr_philo)
			pthread_create(&prog->philo[i].thread, NULL, &beggin, (void *)&prog->philo[i]);
		while (prog->philo_death == 0)
			checker(prog);
	}
}
