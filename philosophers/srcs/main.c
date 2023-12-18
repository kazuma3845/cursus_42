/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:51 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/18 14:15:18 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_general *prog)
{
	int	i;

	i = -1;
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
			prog->philosophers[i].fork_right = &prog->philosophers[i
				+ 1].fork_left;
		if (pthread_create(&prog->philosophers[i].thread, NULL, &beggin,
				&(prog->philosophers[i])) != 0)
			return (-1);
		usleep(1000);
	}
	i = -1;
	while (++i < prog->nbr_philo)
		pthread_join(prog->philosophers[i].thread, NULL);
	return (0);
}

int	ft_init(char **argv, t_general *prog)
{
	pthread_mutex_init(&prog->m_eat, NULL);
	pthread_mutex_init(&prog->m_stop, NULL);
	pthread_mutex_init(&prog->dead, NULL);
	pthread_mutex_init(&prog->print, NULL);
	prog->time_start = get_time();
	prog->nbr_philo = ft_atoi(argv[1]);
	prog->time_die = ft_atoi(argv[2]);
	prog->time_eat = ft_atoi(argv[3]);
	prog->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog->nbr_eat = ft_atoi(argv[5]);
	else
		prog->nbr_eat = -1;
	if (prog->nbr_eat == 0)
		return (1);
	prog->philo_death = 0;
	prog->philosophers = malloc(sizeof(t_philo) * prog->nbr_philo);
	if (prog->philosophers == NULL)
		return (0);
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
	free_all(&prog);
	return (0);
}
