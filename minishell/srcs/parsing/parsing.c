/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:37:43 by frobain           #+#    #+#             */
/*   Updated: 2024/02/12 16:17:10 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* add_redirection: Adds redirection operators and their corresponding file
names to the command node. Handles '>', '>>', '<', and '<<'. */

void	add_redirection(char **cmd_split, int *j, t_cmd *node)
{
	char	*to_add;
	int		i;

	i = *j;
	if ((ft_strlen(cmd_split[*j]) == 2 && (cmd_split[*j][1] == '<'
			|| cmd_split[*j][1] == '>')) || ft_strlen(cmd_split[*j]) == 1)
	{
		if (!cmd_split[*j + 1])
			to_add = ft_strdup(cmd_split[*j]);
		else
		{
			to_add = ft_strjoin(cmd_split[*j], cmd_split[*j + 1]);
			(*j)++;
		}
	}
	else
		to_add = ft_strdup(cmd_split[*j]);
	if (*cmd_split[i] == '>')
		node->dirout = to_add;
	else
		node->dirin = to_add;
}

/* init_cmd: Initializes a command list from a split string. It splits each
command by spaces (considering quotes), creates command nodes, and adds them
to a command list. */

t_cmd	*init_cmd(char **split, char ***env)
{
	int		i;
	t_cmd	*cmd_lst;
	char	**cmd_split;

	i = -1;
	cmd_lst = NULL;
	while (split[++i])
	{
		cmd_split = ft_split_quotes(split[i], ' ');
		if (!cmd_lst)
			cmd_lst = create_new_cmd_node(cmd_split, env);
		else
			cmd_lstadd_back(&cmd_lst, create_new_cmd_node(cmd_split, env));
	}
	if (cmd_lst->args != NULL)
		free_tab(cmd_split);
	return (cmd_lst);
}

bool	check_curr_node_quotes(t_cmd *lst)
{
	int		i;
	int		j;
	char	quotes;

	i = -1;
	while (lst->args[++i])
	{
		j = -1;
		while (lst->args[i][++j])
		{
			while (in_quotes(lst->args[i][j], &quotes))
				j++;
			if (quotes == '\'' || quotes == '"')
				return (false);
		}
	}
	return (true);
}

bool	check_cmds(t_cmd *lst)
{
	t_cmd	*current;

	current = lst;
	while (current != NULL)
	{
		if (!current->cmd)
			return (false);
		current = current->next;
	}
	return (true);
}

/* parsing: Takes the input string, splits it by the pipe '|' character,
initializes command nodes for each split segment, and then processes the
command list. */

int	parsing(const char *input, char ***env, int *code_error)
{
	char	**split;
	t_cmd	*cmd_lst;

	split = ft_split_quotes(input, '|');
	cmd_lst = init_cmd(split, env);
	if (!check_dir(cmd_lst))
		return (ft_error(5, code_error));
	if (ft_strreach(cmd_lst->dirin, "<<") == 1)
		ft_heredoc(cmd_lst, ".temp", code_error);
	if (!check_cmds(cmd_lst))
	{
		free_check_cmd(split, cmd_lst);
		return (ft_error(1, code_error));
	}
	if (!check_quotes(cmd_lst))
		return (ft_error(3, code_error));
	else
	{
		expand_args(cmd_lst, code_error);
		run_cmds(cmd_lst, code_error);
	}
	*env = cmd_lst->env;
	free_tab(split);
	free_cmd_list(cmd_lst);
	return (0);
}
