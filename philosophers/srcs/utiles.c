/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:30:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/20 23:01:05 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)

{
	int					i;
	int					j;
	unsigned long int	retourn;

	i = 0;
	j = 1;
	retourn = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		retourn *= 10;
		retourn += str[i] - '0';
		i++;
	}
	return (retourn * j);
}

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	free_all(t_general *prog)
{
	int	i;

	i = -1;
	while (++i != prog->nbr_philo)
	{
		pthread_mutex_destroy(&prog->philosophers[i].fork_left);
		pthread_mutex_destroy(prog->philosophers[i].fork_right);
	}
	free(prog->philosophers);
	pthread_mutex_destroy(&prog->print);
	pthread_mutex_destroy(&prog->dead);
	pthread_mutex_destroy(&prog->m_eat);
	pthread_mutex_destroy(&prog->m_stop);
}

void	print_msg(char *str, t_philo *philosophers)
{
	int i;

	pthread_mutex_lock(&(philosophers->info->print));
	i = get_time() - philosophers->info->time_start;
	if (!philosophers->info->philo_death && i >= 0 && i <= INT_MAX && !philo_dead(philosophers, 0))
	{
		printf("%lld %d %s\n", get_time() - philosophers->info->time_start,
			philosophers->id, str);
	}
	pthread_mutex_unlock(&(philosophers->info->print));
}

void	ft_sleep(int time)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}
