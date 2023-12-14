/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:30:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/14 17:10:47 by kazuma3845       ###   ########.fr       */
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

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void free_all(t_general *prog)
{
	free(prog->philosophers);
	free(prog->fork_mutex);
}

void	print_msg(char *str, t_philo *philosophers)
{
	if (!philo_dead(philosophers))
	{
		pthread_mutex_lock(&philosophers->general->mutex);
		printf("%d %d %s\n", get_time() - philosophers->general->starting_time, philosophers->id, str);
		pthread_mutex_unlock(&philosophers->general->mutex);
	}
}

void	ft_sleep(int time, t_philo *philo)
{
	int start;

	start = get_time();
	while ((get_time() - start) < time && philo_dead(philo) == 0)
		usleep(50);
}
