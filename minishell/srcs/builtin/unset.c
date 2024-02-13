/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:16:18 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/12 13:26:32 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_equal(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '=')
		i++;
	return (i);
}

int	find_env_index(t_cmd *lst, char *args)
{
	char	**path;
	int		k;

	k = 0;
	path = ft_split(lst->env[k], '=');
	while (ft_strcmp(args, path[0])
		|| (ft_strlen(args) != ft_find_equal(lst->env[k])))
	{
		k++;
		if (lst->env[k] == NULL)
			return (-1);
		free_tab(path);
		path = ft_split(lst->env[k], '=');
	}
	free_tab(path);
	return (k);
}

char	**delet_env(t_cmd *lst, char *args, char **tab, int *code_error)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = find_env_index(lst, args);
	if (k == -1)
	{
		printf("Error : variable not found in env.\n");
		*code_error = 1;
		return (lst->env);
	}
	while (lst->env[i])
	{
		if (i == k)
			i++;
		if (lst->env[i] != NULL)
			tab[j++] = ft_strdup(lst->env[i++]);
	}
	tab[j] = NULL;
	*code_error = 0;
	return (tab);
}

int	built_unset(t_cmd *lst)
{
	int		i;
	char	**tab;
	int		code_error;

	code_error = 0;
	i = 0;
	if (!lst->args[1])
	{
		printf("Please provide at least one variable to unset.\n");
		return (1);
	}
	while (lst->args[++i])
	{
		tab = malloc(sizeof(char *) * ft_arrlen(lst->env));
		tab = delet_env(lst, lst->args[i], tab, &code_error);
		if (code_error != 0)
			break ;
		free_tab(lst->env);
		lst->env = tab;
	}
	return (code_error);
}
