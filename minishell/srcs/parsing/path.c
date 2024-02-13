/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:39:37 by frobain           #+#    #+#             */
/*   Updated: 2024/02/12 13:28:51 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env(t_cmd *lst, char *env, char ***path, char ***commande)
{
	if (env == NULL)
	{
		free(env);
		lst->path = lst->cmd;
		return (1);
	}
	(*path) = ft_split(env, ':');
	(*commande) = ft_split(lst->cmd, ' ');
	return (0);
}

char	*get_path(t_cmd *list)
{
	char	*str;
	char	**commande;
	char	**path;
	char	*env;
	int		i;

	i = -1;
	env = find_in_env(list, "$PATH");
	if (check_env(list, env, &path, &commande) == 1)
		return (list->path = ft_strdup(list->cmd));
	while (path[++i])
	{
		str = ft_strjoin(path[i], "/");
		list->path = ft_strjoin(str, commande[0]);
		free(str);
		if (access(list->path, F_OK | X_OK) == 0)
		{
			leaks(commande, path, env, 1);
			return (list->path);
		}
		free(list->path);
	}
	leaks(commande, path, env, 2);
	list->path = ft_strdup(list->cmd);
	return (list->path);
}

// line 83 = Update SHLVL
char	*increment_shlvl(char *shlvl_str, int *shlvl)
{
	int		lvl;
	char	*lvl_str;
	char	*new_shlvl;

	shlvl_str += 6;
	lvl = ft_atoi(shlvl_str);
	lvl++;
	*shlvl = lvl;
	lvl_str = ft_itoa(lvl);
	new_shlvl = ft_strjoin("SHLVL=", lvl_str);
	free(lvl_str);
	return (new_shlvl);
}

char	**dup_env(char **env, int *shlvl)
{
	int		size;
	int		i;
	char	**venv;

	i = -1;
	size = ft_arrlen(env);
	venv = malloc(sizeof(char *) * size + 1);
	while (env[++i])
	{
		if (ft_strncmp(env[i], "SHLVL", 5) == 0)
			venv[i] = increment_shlvl(env[i], shlvl);
		else
			venv[i] = ft_strdup(env[i]);
	}
	venv[i] = NULL;
	return (venv);
}

void	check_path(t_cmd *list)
{
	if (is_builtin(list) == 0)
		return ;
	else if (is_programm(list))
		return ;
	else
	{
		get_path(list);
		if (ft_strcmp(list->path, list->cmd) == 0)
			return ;
	}
	return ;
}
