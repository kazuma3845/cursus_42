/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:34:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/14 13:37:51 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philosophers;

	philosophers = (t_philo *)arg;
	while (philosophers->general->philosopher_dead == 0)
	{
		
	}
	return (0);
}

void	beggin(t_general *prog)
{
	int	i;

	i = -1;
	prog->starting_time = get_time();
	while (++i < prog->number_of_philosophers)
		pthread_create(&prog->philosophers[i].thread_id, NULL, &routine, (void *)&prog->philosophers[i]);
	i = -1;
	while (++i < prog->number_of_philosophers)
		pthread_join(prog->philosophers[i].thread_id, NULL);
}
