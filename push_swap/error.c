/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:05:38 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:07 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_dup(t_stack **a, int number)
{
	int	x;

	x = 0;
	if (!(*a))
		return (x);
	if ((*a)->number == number)
		return (1);
	x += error_dup(&(*a)->next, number);
	return (x);
}

int	error_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
			i++;
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack **a)
{
	if (*a == NULL)
		return ;
	if ((*a)->next != NULL)
		free_stack(&((*a)->next));
	free(*a);
}

void	error(t_stack **a)
{
	if ((*a))
		free_stack(a);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
