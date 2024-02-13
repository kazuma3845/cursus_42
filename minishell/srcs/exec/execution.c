/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:03:34 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 15:56:09 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_child(t_cmd *cmd, int *fd, int *in_fd, int *out_fd)
{
	if (*in_fd != 0)
	{
		dup2(*in_fd, STDIN_FILENO);
		close(*in_fd);
	}
	if (cmd->next)
		handle_next_cmd(cmd, fd, in_fd, out_fd);
	else if (configure_redirections(cmd, in_fd, out_fd) != 0)
		exit(4);
	else if (*out_fd != -1)
	{
		dup2(*out_fd, STDOUT_FILENO);
		close(*out_fd);
	}
	if (cmd->builtin)
		exit(cmd->builtin(cmd));
	else
	{
		execve(cmd->path, cmd->args, cmd->env);
		exit(127);
	}
}

static void	exec_parent(t_cmd *cmd, int *fd, int *in_fd)
{
	if (cmd->builtin == built_cd && !cmd->next)
		built_cd(cmd);
	if (cmd->builtin == built_export && !cmd->next && ft_arrlen(cmd->args) != 1)
		built_export(cmd);
	if (cmd->builtin == built_unset && !cmd->next)
		built_unset(cmd);
	if (*in_fd != 0)
		close(*in_fd);
	if (cmd->next)
	{
		*in_fd = fd[0];
		close(fd[1]);
	}
}

void	exec_pipeline(t_cmd *cmd, int *code_error)
{
	pid_t					pid;
	int						fd[2];
	t_exec_pipeline_context	ctx;

	initialize_exec_pipeline(&ctx);
	while (cmd)
	{
		if (cmd->next && pipe(fd) == -1)
			exit(ft_error(7, code_error));
		if ((cmd->builtin == built_exit || cmd->builtin == built_unset)
			&& !cmd->next)
			ft_error(cmd->builtin(cmd), code_error);
		else
		{
			pid = fork();
			if (pid == 0)
				exec_child(cmd, fd, &ctx.in_fd, &ctx.out_fd);
			else if (pid < 0)
				exit(ft_error(8, code_error));
			exec_parent(cmd, fd, &ctx.in_fd);
			add_pid(&ctx.pid_list, pid);
		}
		cmd = cmd->next;
	}
	cleanup_exec_pipeline(&ctx, code_error);
}

void	run_cmds(t_cmd *cmd_lst, int *code_error)
{
	exec_pipeline(cmd_lst, code_error);
}
