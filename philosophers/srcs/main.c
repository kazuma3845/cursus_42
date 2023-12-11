/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:51 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/11 15:12:00 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *algo(void *arg)
{
	int timer = 0;
	int philo = 1;
	arg = 0;
	printf("%d %d has taken a fork", timer++, philo);
	printf("%d %d  is eating", timer++, philo);
	printf("%d %d  is sleeping", timer++, philo);
	printf("%d %d  is thinking", timer++, philo);
	printf("%d %d  died", timer, philo);
	return (0);
}

void tread_start(void)
{
	int i;
	pthread_t tid[2]; 

	i = 0;
	pthread_create(&(tid[i]), NULL, &algo, NULL);
}

int main(int argc, char **argv)
{
	t_tab tab;

	if (argc < 5 || argc > 6)
		return (0);
	tab.nbr_philo = atoi(argv[1]);
	tab.time_death = atoi(argv[2]);
	tab.time_eat = atoi(argv[3]);
	tab.time_sleep = atoi(argv[4]);
	if (argc == 6)
		tab.nbr_eat = atoi(argv[5]);
	tread_start();
	return (0);
}
