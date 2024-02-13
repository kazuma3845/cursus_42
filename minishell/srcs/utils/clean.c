/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:39:33 by frobain           #+#    #+#             */
/*   Updated: 2024/02/12 16:13:01 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

void	free_cmd_list(t_cmd *cmd_lst)
{
	t_cmd	*current;
	t_cmd	*tmp;

	current = cmd_lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->path);
		free(tmp->cmd);
		free_tab(tmp->args);
		free(tmp->dirin);
		free(tmp->dirout);
		free(tmp);
	}
}

void	leaks(char **commande, char **path, char *env, int i)
{
	if (i == 1)
	{
		free_tab(commande);
		free_tab(path);
		free(env);
	}
	if (i == 2)
	{
		free_tab(path);
		free_tab(commande);
		free(env);
	}
}

void	free_check_cmd(char **split, t_cmd *cmd_lst)
{
	free(cmd_lst);
	free_tab(split);
}
