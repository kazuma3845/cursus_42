/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:11:22 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/18 12:46:38 by tomuller         ###   ########.fr       */
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

typedef struct s_philo
{
	int					id;
	int					food_count;
	bool				is_eating;
	pthread_t			thread;
	long int			last_eat;
	struct s_general	*info;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		fork_left;
}						t_philo;

typedef struct s_general
{
	int					philo_eat;
	int					nbr_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					nbr_eat;
	int					philo_death;
	long int			time_start;
	t_philo				*philosophers;
	pthread_mutex_t		print;
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_eat;
	pthread_mutex_t		dead;
}						t_general;

//	main.c
int						main(int argc, char **argv);
int						init_philo(t_general *prog);
int						ft_init(char **argv, t_general *prog);
//	utiles.c
int						ft_atoi(const char *str);
int						get_time(void);
void					free_all(t_general *prog);
void					print_msg(char *str, t_philo *philosophers);
void					ft_sleep(int time, t_philo *philo);
//	error.c
int						check_arg(int argc, char **argv);
int						check_char(int argc, char **argv);
int						ft_isdigit(char *c);
//	algo.c
void					*beggin(void *arg);
void					*routine(void *arg);
// philo_action.c
void					philo_eat(t_philo *philo);
int						philo_dead(t_philo *philo, int death);
void					philo_fork(t_philo *philo);

#endif