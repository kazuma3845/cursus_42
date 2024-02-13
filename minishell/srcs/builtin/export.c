/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:36:22 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 13:02:37 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ismaj(char *c)
{
	int	i;

	i = 0;
	while ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= '0' && c[i] <= '9'))
	{
		if (c[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_maj_args(char **arg)
{
	if (arg[1] == NULL || ft_ismaj(arg[0]) == 0)
		return (0);
	return (1);
}

int	built_export(t_cmd *lst)
{
	int		i;
	char	**tab;
	char	*test;

	i = 0;
	if (lst->args[1] == NULL)
	{
		return (built_env(lst));
	}
	while (lst->args[++i])
	{
		tab = ft_split(lst->args[i], '=');
		if (check_maj_args(tab) == 0)
		{
			return (11);
		}
		test = ft_strjoin(lst->args[i], "");
		change_env(lst, test, tab[0]);
		free_tab(tab);
	}
	return (0);
}
