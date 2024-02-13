/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:40:34 by frobain           #+#    #+#             */
/*   Updated: 2024/02/06 16:38:43 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* init_map: Initializes an array of builtin_map structures with common shell
   built-in command names and their corresponding function pointers. */

void	init_map(t_builtin_map *builtin_map)
{
	builtin_map[0].name = "echo";
	builtin_map[0].func = built_echo;
	builtin_map[1].name = "cd";
	builtin_map[1].func = built_cd;
	builtin_map[2].name = "pwd";
	builtin_map[2].func = built_pwd;
	builtin_map[3].name = "export";
	builtin_map[3].func = built_export;
	builtin_map[4].name = "unset";
	builtin_map[4].func = built_unset;
	builtin_map[5].name = "env";
	builtin_map[5].func = built_env;
	builtin_map[6].name = "exit";
	builtin_map[6].func = built_exit;
	builtin_map[7].name = NULL;
	builtin_map[7].func = NULL;
}

bool	in_quotes(char c, char *curr_quotes)
{
	if (c == '\0')
		return (NULL);
	if (c == *curr_quotes)
	{
		*curr_quotes = '\0';
		return (false);
	}
	else if (*curr_quotes == '\0' && (c == '"' || c == '\''))
	{
		*curr_quotes = c;
		return (true);
	}
	return (*curr_quotes != '\0');
}

/* init_node_variables: Initializes the variables of a command node with
default values and allocates memory for args. */

t_cmd	*init_node_variables(t_cmd *node)
{
	node->cmd = NULL;
	node->next = NULL;
	node->path = NULL;
	node->args = NULL;
	node->dirin = NULL;
	node->dirout = NULL;
	return (node);
}
