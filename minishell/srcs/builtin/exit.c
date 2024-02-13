/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:15:21 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 13:09:28 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_args_exit(t_cmd *lst)
{
	int	i;

	i = -1;
	if (!lst->args[1])
		return (0);
	if (ft_arrlen(lst->args) > 2)
	{
		printf("Error : exit takes 1 argument maximum.\n");
		return (1);
	}
	while (lst->args[1][++i])
	{
		if (!ft_isdigit(lst->args[1][i]))
		{
			printf("Error : please provide valid exit number (only num).\n");
			return (1);
		}
	}
	return (0);
}

int	built_exit(t_cmd *lst)
{
	int	code_error;

	if (check_args_exit(lst) != 0)
		return (1);
	if (ft_arrlen(lst->args) == 2)
		code_error = ft_atoi(lst->args[1]);
	else
	{
		code_error = 0;
		free_cmd_list(lst);
	}
	exit(code_error);
}
