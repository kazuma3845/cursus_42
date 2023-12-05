/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:45:29 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/05 13:42:07 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipiex.h"

void	exce(char *argv, char **env)
{
	char	*chemin;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	chemin = get_path(cmd[0], env);
	if (execve(chemin, cmd, env) == -1)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_tab(cmd);
		exit(0);
	}
}

void	child(char **argv, int *pfd, char **env)
{
	int	fd;

	fd = open_fd(argv[1], 0);
	dup2(fd, 0);
	dup2(pfd[1], 1);
	close(pfd[0]);
	exce(argv[2], env);
}

void	parent(char **argv, int *pfd, char **env)
{
	int	fd;

	fd = open_fd(argv[4], 1);
	dup2(fd, 1);
	dup2(pfd[0], 0);
	close(pfd[1]);
	exce(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		pfd[2];
	pid_t	pid;

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
