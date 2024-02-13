/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:35:55 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 10:44:59 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* update_cmd_with_builtin: Updates the command node with the corresponding
builtin function if the command matches a builtin command. */

void	update_cmd_with_builtin(t_cmd *node)
{
	int				i;
	t_builtin_map	builtin_map[8];

	init_map(builtin_map);
	i = 0;
	while (builtin_map[i].name != NULL)
	{
		if (strcmp(node->cmd, builtin_map[i].name) == 0)
		{
			node->builtin = builtin_map[i].func;
			return ;
		}
		i++;
	}
	node->builtin = NULL;
}

/* add_args: Adds an argument to the command node. It reallocates the args
array to accommodate the new argument. */

void	add_args(char *arg, t_cmd *node, int *i)
{
	char	**new_args;
	int		k;

	new_args = malloc((*i + 2) * sizeof(char *));
	if (!new_args)
		return ;
	k = 0;
	while (k < *i)
	{
		new_args[k] = node->args[k];
		k++;
	}
	new_args[*i] = ft_strdup(arg);
	new_args[*i + 1] = NULL;
	if (*i > 0)
		free(node->args);
	node->args = new_args;
	if (*i == 0)
		node->cmd = ft_strdup(arg);
	(*i)++;
}

/* create_new_cmd_node: Creates a new command node from a split command string.
It handles redirections and arguments and checks for builtins and paths. */

t_cmd	*create_new_cmd_node(char **cmd_split, char ***env)
{
	t_cmd	*new_node;
	int		j;
	int		i;

	i = 0;
	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
		return (NULL);
	new_node = init_node_variables(new_node);
	j = 0;
	while (cmd_split[j])
	{
		if (*cmd_split[j] == '<' || *cmd_split[j] == '>')
			add_redirection(cmd_split, &j, new_node);
		else
			add_args(cmd_split[j], new_node, &i);
		j++;
	}
	new_node->env = *env;
	if (new_node->args == NULL)
		return (new_node);
	check_path(new_node);
	update_cmd_with_builtin(new_node);
	return (new_node);
}

/* cmd_lastlst: Returns the last node in a command linked list. */

t_cmd	*cmd_lastlst(t_cmd *lst)
{
	t_cmd	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

/*
cmd_lstadd_back: Adds a new command node to the end of a command linked list.
*/
void	cmd_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = cmd_lastlst(*lst);
		last->next = new;
	}
}
