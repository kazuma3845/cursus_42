/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:04:07 by kazuma3845        #+#    #+#             */
/*   Updated: 2024/02/12 11:06:04 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env(t_cmd *lst, char *pwd)
{
	char	**tab;
	int		i;

	i = ft_arrlen(lst->env);
	tab = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (lst->env[++i])
	{
		tab[i] = ft_strdup(lst->env[i]);
	}
	tab[i++] = pwd;
	tab[i] = NULL;
	free_tab(lst->env);
	lst->env = tab;
}

int	is_env(t_cmd *lst, char *modif)
{
	int		i;
	char	**key;

	i = -1;
	while (lst->env[++i])
	{
		key = ft_split(lst->env[i], '=');
		if (ft_strcmp(modif, key[0]) == 0)
		{
			free_tab(key);
			return (1);
		}
		free_tab(key);
	}
	return (0);
}

void	change_env(t_cmd *lst, char *pwd, char *key)
{
	int		size;
	char	**path;

	if (is_env(lst, key) == 1)
	{
		size = 0;
		path = ft_split(lst->env[size], '=');
		while (ft_strcmp(key, path[0]) != 0)
		{
			size++;
			free_tab(path);
			path = ft_split(lst->env[size], '=');
		}
		free_tab(path);
		free(lst->env[size]);
		lst->env[size] = pwd;
	}
	else
		add_env(lst, pwd);
}
