/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:18:35 by frobain           #+#    #+#             */
/*   Updated: 2024/02/12 13:45:26 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// line 24 = Ferme l'ancien fd si nécessaire
int	configure_input_redirection(t_cmd *cmd, int *in_fd)
{
	char	*in_filename;

	if (cmd->dirin)
	{
		in_filename = cmd->dirin;
		if (*in_filename == '<')
			in_filename++;
		if (*in_fd != -1)
		{
			close(*in_fd);
		}
		*in_fd = open(in_filename, O_RDONLY);
		if (*in_fd == -1)
			return (1);
	}
	return (0);
}

// line 54 = Ferme l'ancien fd si nécessaire
int	configure_output_redirection(t_cmd *cmd, int *out_fd)
{
	char	*out_filename;
	int		oflag;

	if (cmd->dirout)
	{
		out_filename = cmd->dirout;
		if (*out_filename == '>')
			out_filename++;
		if (*out_filename == '>')
		{
			oflag = O_CREAT | O_APPEND | O_WRONLY;
			out_filename++;
		}
		else
			oflag = O_CREAT | O_TRUNC | O_WRONLY;
		if (*out_fd != -1)
		{
			close(*out_fd);
		}
		*out_fd = open(out_filename, oflag, 0644);
		if (*out_fd == -1)
			return (1);
	}
	return (0);
}

int	configure_redirections(t_cmd *cmd, int *in_fd, int *out_fd)
{
	if (configure_input_redirection(cmd, in_fd) != 0)
		return (1);
	if (configure_output_redirection(cmd, out_fd) != 0)
		return (1);
	return (0);
}

void	initialize_exec_pipeline(t_exec_pipeline_context *ctx)
{
	ctx->in_fd = 0;
	ctx->out_fd = -1;
	ctx->pid_list = NULL;
	ctx->saved_stdout = dup(STDOUT_FILENO);
	ctx->saved_stdin = dup(STDIN_FILENO);
}

void	cleanup_exec_pipeline(t_exec_pipeline_context *ctx, int *code_error)
{
	close(ctx->saved_stdout);
	close(ctx->saved_stdin);
	if (ctx->in_fd != 0)
		close(ctx->in_fd);
	wait_pids(ctx->pid_list, code_error);
	free_pid_list(ctx->pid_list);
}
