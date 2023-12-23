/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:10:51 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/23 15:09:25 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_general *prog)
{
	int	i;

	i = -1;
	while (++i < prog->nbr_philo)
	{
		prog->philo[i].id = i + 1;
		prog->philo[i].info = prog;
		prog->philo[i].t_lastmeal = 0;
		prog->philo[i].meals_eaten = 0;
		prog->philo[i].left_fork = i;
		prog->philo[i].right_fork = (i + 1) % prog->nbr_philo;
	}
}

int	ft_init(char **argv, t_general *prog)
{
	int	i;

	i = -1;
	prog->philo_death = 0;
	prog->end_meal = 0;
	prog->error = 0;
	prog->nbr_philo = ft_atoi(argv[1]);
	prog->time_die = ft_atoi(argv[2]);
	prog->time_eat = ft_atoi(argv[3]);
	prog->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		prog->max_meals = ft_atoi(argv[5]);
	else
		prog->max_meals = 0;
	prog->philo = malloc(sizeof(t_philo) * prog->nbr_philo);
	prog->fork = malloc(sizeof(pthread_mutex_t) * prog->nbr_philo);
	if (prog->philo == NULL || prog->fork == NULL)
		return (1);
	pthread_mutex_init(&prog->checker, NULL);
	pthread_mutex_init(&prog->cout, NULL);
	while (++i != prog->nbr_philo)
		pthread_mutex_init(&prog->fork[i], NULL);
	init_philo(prog);
	prog->time_start = get_time();
	return (0);
}

int	main(int argc, char **argv)
{
	t_general	prog;

	if (check_arg(argc, argv) == 0)
		return (0);
	if (ft_init(argv, &prog) == 0)
		start_prog(&prog);
	free_all(&prog);
	return (0);
}
