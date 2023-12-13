/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:51 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/13 16:01:10 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void ft_init(int argc, char **argv, t_philo *lst)
{
	lst->nbr_philo = ft_atoi(argv[1]);
	lst->time_death = ft_atoi(argv[2]);
	lst->time_eat = ft_atoi(argv[3]);
	lst->time_sleep = ft_atoi(argv[4]);
	lst->starting_time = get_time();
	lst->count_death = 0;
	lst->fourchette = 2;
	if (argc == 6)
		lst->eat_max = ft_atoi(argv[5]);
	else
		lst->eat_max = -1;
}

void *routine(void *arg)
{
	t_philo *lst;

	lst = (t_philo *)arg;
	printf("test %d\n", lst->eat_max);
	return (0);
}

void	beggin(t_programme *prog)
{
	int i;

	i = -1;
	prog->lst->th = malloc(prog->lst->nbr_philo * sizeof(pthread_t));
	while (++i < prog->lst->nbr_philo)
		pthread_create(&prog->lst->th[i], NULL, &routine, (void *)&prog->lst[i]);
	i = -1;
	while (++i < prog->lst->nbr_philo)
		pthread_join(prog->lst->th[i], NULL);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	mutex;
	t_programme prog;

	if (argc < 5 || argc > 6)
		return (0);
	ft_init(argc, argv, prog.lst);
	pthread_mutex_init(&mutex, NULL);
	beggin(&prog);
	pthread_mutex_destroy(&mutex);
	return (0);
}
