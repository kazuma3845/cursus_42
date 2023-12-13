/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:11:22 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/13 15:48:00 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
	int count_death;
	int nbr_philo;
	int time_eat;
	int	time_sleep;
	int time_death;
	int fourchette;
	int	eat_max;
	int starting_time;

	pthread_t		*th;
	struct s_programme *prog;
}		t_philo;

typedef struct s_programme
{
    t_philo *lst;
    pthread_mutex_t *mutex;
	int i;
} t_programme;

int		main(int argc, char **argv);
int		ft_atoi(const char *str);
int	get_time(void);

#endif