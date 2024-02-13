/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:59:22 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/08 16:28:40 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_programm(t_cmd *lst)
{
	int	i;

	i = 0;
	while (lst->cmd[i + 1] != '\0')
		i++;
	while (ft_isprint(lst->cmd[i]) && lst->cmd[i] != '/')
		i--;
	if (lst->cmd[i] == '/')
	{
		lst->path = ft_strdup(lst->cmd);
		return (true);
	}
	return (false);
}

int	is_builtin(t_cmd *lst)
{
	if (ft_strncmp(lst->args[0], "echo", ft_strlen(lst->args[0])) == 0
		|| ft_strncmp(lst->args[0], "pwd", ft_strlen(lst->args[0])) == 0
		|| ft_strncmp(lst->args[0], "exit", ft_strlen(lst->args[0])) == 0
		|| ft_strncmp(lst->args[0], "cd", ft_strlen(lst->args[0])) == 0
		|| ft_strncmp(lst->args[0], "export", ft_strlen(lst->args[0])) == 0
		|| ft_strncmp(lst->args[0], "unset", ft_strlen(lst->args[0])) == 0
		|| ft_strncmp(lst->args[0], "env", ft_strlen(lst->args[0])) == 0)
		return (0);
	return (1);
}

int	ft_strreach(char *str, char *cmp)
{
	int	i;
	int	j;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i])
	{
		j = 0;
		if (str[i] == cmp[j])
		{
			while (str[i] == cmp[j])
			{
				i++;
				j++;
				if (cmp[j] == '\0')
					return (1);
			}
		}
	}
	return (0);
}

bool	check_quotes(t_cmd *lst)
{
	t_cmd	*current;

	current = lst;
	while (current != NULL)
	{
		if (!check_curr_node_quotes(current))
			return (false);
		current = current->next;
	}
	return (true);
}

bool	check_dir(t_cmd *lst)
{
	t_cmd	*current;

	current = lst;
	while (current != NULL)
	{
		if (current->dirin)
		{
			if ((ft_strlen(current->dirin) == 2 && current->dirin[1] == '<')
				|| ft_strlen(current->dirin) == 1)
				return (false);
		}
		if (current->dirout)
		{
			if ((ft_strlen(current->dirout) == 2 && current->dirout[1] == '>')
				|| ft_strlen(current->dirout) == 1)
				return (false);
		}
		current = current->next;
	}
	return (true);
}
