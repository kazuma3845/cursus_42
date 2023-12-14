/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:51 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/14 16:35:48 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex(t_general *prog)
{
	int	i;

	i = -1;
	prog->fork_mutex = malloc(sizeof(pthread_mutex_t)
			* prog->number_of_philosophers);
	if (prog->fork_mutex == NULL)
		return (0);
	while (++i != prog->number_of_philosophers)
		pthread_mutex_init(&prog->fork_mutex[i], NULL);
	pthread_mutex_init(&prog->mutex, NULL);
	return (1);
}

int	init_philo(t_general *prog)
{
	int	i;

	i = 0;
	prog->philosophers = malloc(sizeof(t_philo) * prog->number_of_philosophers);
	while (i < prog->number_of_philosophers)
	{
		prog->philosophers[i].id = i + 1;
		prog->philosophers[i].time_to_die = prog->time_to_die;
		prog->philosophers[i].time_to_eat = prog->time_to_eat;
		prog->philosophers[i].time_to_sleep = prog->time_to_sleep;
		prog->philosophers[i].left_fork = &prog->fork_mutex[i];
		prog->philosophers[i].right_fork = &prog->fork_mutex[(i + 1)
			% prog->number_of_philosophers];
		prog->philosophers[i].general = prog;
		prog->philosophers[i].last_meal = 0;
		prog->philosophers[i].is_eating = 0;
		prog->philosophers[i].number_of_meals = 0;
		i++;
	}
	return (1);
}

int	ft_init(char **argv, t_general *prog)
{
	prog->number_of_philosophers = ft_atoi(argv[1]);
	prog->time_to_die = ft_atoi(argv[2]);
	prog->time_to_eat = ft_atoi(argv[3]);
	prog->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog->number_of_meals = ft_atoi(argv[5]);
	else
		prog->number_of_meals = -1;
	prog->philosopher_dead = 0;
	if (mutex(prog) == 0)
		return (0);
	if (init_philo(prog) == 0)
		return (0);
	return (1);
}

void joint_thread(t_general *prog)
{
	int i;

	i = -1;
	while (++i != prog->number_of_philosophers)
		pthread_join(prog->philosophers[i].thread_id, NULL);
}

int	main(int argc, char **argv)
{
	t_general	prog;

	if (check_arg(argc, argv) == 0)
		return (0);
	if (ft_init(argv, &prog) == 1)
	{
		beggin(&prog);
		algo(&prog);
		joint_thread(&prog);
		free_all(&prog);
	}
	return (0);
}
