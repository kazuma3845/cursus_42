/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:30:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/23 15:10:30 by tomuller         ###   ########.fr       */
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
		pthread_join(prog->philo[i].thread, NULL);
	i = -1;
	while (++i != prog->nbr_philo)
	{
		pthread_mutex_destroy(&prog->fork[i]);
	}
	pthread_mutex_destroy(&prog->cout);
	pthread_mutex_destroy(&prog->checker);
	free(prog->philo);
	free(prog->fork);
}

void	print_msg(char *str, t_philo *philosophers)
{
	if (!philosophers->info->philo_death)
	{
		pthread_mutex_lock(&(philosophers->info->cout));
		printf("%lld %d %s\n", get_time() - philosophers->info->time_start,
			philosophers->id, str);
		pthread_mutex_unlock(&(philosophers->info->cout));
	}
}

void	ft_sleep(int time, t_general *prog)
{
	long long	start;
	long long	timer;

	start = get_time() - prog->time_start;
	while (1)
	{
		timer = get_time() - prog->time_start - start;
		if (timer >= time)
			break ;
		usleep(1000);
	}
}
