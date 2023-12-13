/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:51 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/12 21:33:41 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int argc, char **argv)
{
	int				i;
	pthread_t		tid[2];
	pthread_mutex_t	mutex;

	if (argc < 5 || argc > 6)
		return (0);
	argv = NULL;
	i = 1;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&(tid[0]), NULL, &algo, (void *)&i);
	i++;
	pthread_create(&(tid[1]), NULL, &algo, (void *)&i);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}

void	*algo(void *arg)
{
	int	timer;
	pthread_mutex_t	mutex;

	timer = 1;
	pthread_mutex_lock(&mutex);
	printf("%d %d has taken a fork\n", timer, (int)arg);
	printf("%d %d has taken a fork\n", timer, (int)arg);
	printf("%d %d is eating\n", timer++, (int)arg);
	// usleep(ft_atoi(argv[4]));
	printf("%d %d is sleeping\n", timer++, (int)arg);
	// usleep(ft_atoi(argv[5]));
	printf("%d %d is thinking\n", timer++, (int)arg);
	// usleep(time_for_wait_after_eat);
	// if (argv[3] == (argv[4] + argv[5]))
		printf("%d %d died\n", timer, (int)arg);
	pthread_mutex_unlock(&mutex);
	return (0);
}
