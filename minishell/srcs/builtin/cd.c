/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:04 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/13 14:00:50 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_2(t_cmd *lst, char *access, char *oldpwd)
{
	char	*check;
	char	*pwd;

	pwd = ft_strjoin("PWD=", access);
	change_env(lst, pwd, "PWD");
	check = ft_strjoin("OLD", pwd);
	if (ft_strcmp(oldpwd, check) != 0)
		change_env(lst, oldpwd, "OLDPWD");
	else
	{
		free(check);
		free(oldpwd);
		return (10);
	}
	free(check);
	return (0);
}

int	real_cd(t_cmd *lst, char *env, char *oldpwd)
{
	char	**path;
	char	*access;
	int		result;

	if (lst->args[1] == NULL)
		chdir(env);
	else
	{
		if (lst->args[1][0] == '~' && lst->args[1][1] != '\0')
		{
			path = ft_split(lst->args[1], '~');
			access = ft_strjoin(env, path[0]);
			chdir(access);
			free(access);
			free_tab(path);
		}
		else if (lst->args[1][0] == '~')
			chdir(env);
		else
			chdir(lst->args[1]);
	}
	access = getcwd(NULL, 0);
	result = cd_2(lst, access, oldpwd);
	free(access);
	return (result);
}

int	built_cd(t_cmd *lst)
{
	char	*oldpwd;
	char	*env;
	char	*access;
	int		result;

	if (ft_arrlen(lst->args) > 2)
		return (9);
	if (lst->args[1] && ft_strcmp(lst->args[1], ".") == 0
		&& ft_strlen(lst->args[1]) == 1)
		return (0);
	env = find_in_env(lst, "$HOME");
	access = getcwd(NULL, 0);
	if (!lst->args[1] && ft_strcmp(env, access) == 0)
	{
		free(access);
		free(env);
		return (0);
	}
	oldpwd = ft_strjoin("OLDPWD=", access);
	free(access);
	result = real_cd(lst, env, oldpwd);
	free(env);
	return (result);
}
