/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:25:06 by neah              #+#    #+#             */
/*   Updated: 2024/02/12 13:44:26 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect(int oldfd, int newfd, int *code_error)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) != -1)
			close(oldfd);
		else
			return (ft_error(4, code_error));
	}
	return (0);
}

void	add_pid(t_pid_list **pid_list, int pid)
{
	t_pid_list	*new;

	new = malloc(sizeof(t_pid_list));
	if (!new)
		return ;
	new->pid = pid;
	new->next = *pid_list;
	*pid_list = new;
}

void	free_pid_list(t_pid_list *pid_list)
{
	t_pid_list	*tmp;

	while (pid_list)
	{
		tmp = pid_list;
		pid_list = pid_list->next;
		free(tmp);
	}
}

void	wait_pids(t_pid_list *pid_list, int *code_error)
{
	int	status;

	while (pid_list != NULL)
	{
		if (waitpid(pid_list->pid, &status, 0) > 0)
		{
			if (WIFEXITED(status))
			{
				if (WEXITSTATUS(status) != 0)
					ft_error(WEXITSTATUS(status), code_error);
				else
					*code_error = WEXITSTATUS(status);
			}
			else if (WIFSIGNALED(status))
				ft_error(128 + WTERMSIG(status), code_error);
		}
		pid_list = pid_list->next;
	}
}

void	handle_next_cmd(t_cmd *cmd, int *fd, int *in_fd, int *out_fd)
{
	close(fd[0]);
	if (configure_redirections(cmd, in_fd, out_fd) != 0)
		exit(1);
	if (*out_fd != -1)
	{
		dup2(*out_fd, STDOUT_FILENO);
		close(*out_fd);
	}
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}
