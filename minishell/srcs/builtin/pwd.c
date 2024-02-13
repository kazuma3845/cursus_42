/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:32:33 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/13 13:36:13 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_pwd(t_cmd *lst)
{
	char	**path;
	int		size;
	char	*pwd;

	size = 0;
	path = ft_split(lst->env[size], '=');
	while (ft_strncmp("PWD", path[0], ft_strlen("PWD")))
	{
		size++;
		free_tab(path);
		path = ft_split(lst->env[size], '=');
	}
	free_tab(path);
	pwd = ft_strchr(lst->env[size], '=');
	pwd = ft_strchr(pwd, pwd[1]);
	printf("%s\n", pwd);
	return (0);
}
