/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuma3845 <kazuma3845@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:11:22 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/22 13:20:45 by kazuma3845       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_general	t_general;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			meals_eaten;
	long long	t_lastmeal;
	int			left_fork;
	int			right_fork;
	t_general	*info;
}						t_philo;
typedef struct s_general
{
	int				nbr_philo;
	long long		time_start;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int				max_meals;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	cout;
	pthread_mutex_t	checker;
	int				error;
	int				end_meal;
	int				philo_death;
}						t_general;

//	main.c
int						main(int argc, char **argv);
void					init_philo(t_general *prog);
int						ft_init(char **argv, t_general *prog);
//	utiles.c
int						ft_atoi(const char *str);
long long				get_time(void);
void					free_all(t_general *prog);
void					print_msg(char *str, t_philo *philosophers);
void					ft_sleep(int time, t_general *prog);
//	error.c
int						check_arg(int argc, char **argv);
int						check_char(int argc, char **argv);
int						ft_isdigit(char *c);
//	algo.c
void					*beggin(void *arg);
void					*one_philo(void *arg);
void					checker(t_general *prog);
void 					start_prog(t_general *prog);
// philo_action.c
void					philo_eat(t_philo *philo);
void					philo_dead(t_philo *philo);
void					philo_sleep(t_philo *philo);
void					philo_think(t_philo *philo);

#endif