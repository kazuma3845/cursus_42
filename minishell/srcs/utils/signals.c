/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:29:39 by frobain           #+#    #+#             */
/*   Updated: 2024/02/12 15:22:41 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* handler: A signal handler function to handle SIGINT and SIGQUIT signals.
   It defines custom behavior for these signals in the shell. */

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler2(int signal)
{
	if (signal == SIGINT)
		rl_on_new_line();
}

void	signal_setup(int handler_num)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
	sa.sa_flags = SA_RESTART;
	if (handler_num == 1)
		sa.sa_handler = handler;
	else if (handler_num == 2)
		sa.sa_handler = handler2;
	else
		return ;
	sigaction(SIGINT, &sa, NULL);
}
