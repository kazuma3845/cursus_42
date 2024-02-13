/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:40:01 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 13:02:46 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_env(t_cmd *lst)
{
	int	i;

	i = -1;
	if (ft_arrlen(lst->args) != 1)
	{
		return (9);
	}
	while (lst->env[++i])
		ft_putendl_fd(lst->env[i], 1);
	return (0);
}
