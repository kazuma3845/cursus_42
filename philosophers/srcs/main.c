/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:51 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/15 16:11:20 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex(t_general *prog)
{
	prog->philosophers = malloc(sizeof(pthread_mutex_t)
			* prog->nbr_philo);
	if (prog->philosophers == NULL)
		return (0);
	pthread_mutex_init(&prog->m_eat, NULL);
	pthread_mutex_init(&prog->m_stop, NULL);
	pthread_mutex_init(&prog->dead, NULL);
	pthread_mutex_init(&prog->print, NULL);
	return (1);
}

int	init_philo(t_general *prog)
{
	int	i;

	i = -1;
	prog->philosophers = malloc(sizeof(t_philo) * prog->nbr_philo);
	while (++i < prog->nbr_philo)
	{
		prog->philosophers[i].id = i + 1;
		prog->philosophers[i].info = prog;
		prog->philosophers[i].last_eat = 0;
		prog->philosophers[i].food_count = 0;
		prog->philosophers[i].fork_right = NULL;
		pthread_mutex_init(&(prog->philosophers[i].fork_left), NULL);
		if (i == prog->nbr_philo - 1)
			prog->philosophers[i].fork_right = &prog->philosophers[0].fork_left;
		else
			prog->philosophers[i].fork_right = &prog->philosophers[i + 1].fork_left;
		if (pthread_create(&prog->philosophers[i].thread, NULL, &beggin, &(prog->philosophers[i])) != 0)
			return (-1);
	}
	i = -1;
	while (++i < prog->nbr_philo)
	{
		if (pthread_join(prog->philosophers[i].thread, NULL) != 0)
			return (-1);
	}
	return (0);
}

int	ft_init(char **argv, t_general *prog)
{
	prog->nbr_philo = ft_atoi(argv[1]);
	prog->time_die = ft_atoi(argv[2]);
	prog->time_eat = ft_atoi(argv[3]);
	prog->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog->nbr_eat = ft_atoi(argv[5]);
	else
		prog->nbr_eat = -1;
	if (argv[5] == 0)
		return (1);
	prog->philo_death = 0;
	if (mutex(prog) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_general	prog;

	if (check_arg(argc, argv) == 0)
		return (0);
	if (ft_init(argv, &prog) == 1)
	{
		free(prog.philosophers);
		return (0);
	}
	init_philo(&prog);
	return (0);
}
