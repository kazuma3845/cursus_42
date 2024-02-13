/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:03:11 by tomuller          #+#    #+#             */
/*   Updated: 2024/02/12 13:02:53 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	built_echo(t_cmd *lst)
{
	int	i;

	i = 1;
	if (ft_arrlen(lst->args) == 1)
	{
		printf("\n");
		return (0);
	}
	if (ft_strcmp(lst->args[1], "-n") == 0)
		i++;
	while (lst->args[i])
	{
		printf("%s", lst->args[i++]);
		if (lst->args[i] != NULL)
			printf(" ");
	}
	if (ft_strcmp(lst->args[1], "-n") != 0)
		printf("\n");
	return (0);
}
