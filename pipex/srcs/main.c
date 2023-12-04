/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:45:29 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/04 14:23:08 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/pipiex.h"

void	child(char **argv, int *pfd, char **env)
{
	int	fd;

	fd = open_fd(argv[1], 0);
	dup2(fd, 0);
	dup2(pfd[1], 1);
	close(pfd[0]);
	exce();
}

void	parent(char **argv, int *pfd, char **env)
{
	int	fd;

	fd = open_fd(argv[4], 1);
	dup2(fd, 1);
	dup2(pfd[0], 0);
	close(pfd[1]);
	exce();
}

int	main(int argc, char **argv, char **env)
{
	int	pfd[2];
	pid_t pid;

	if (argc != 5)
		error_arg(1);
	if (pipe(pfd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(argv, pfd, env);
	parent(argv, pfd, env);
}
