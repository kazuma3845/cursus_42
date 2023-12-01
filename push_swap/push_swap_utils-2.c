/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils-2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:06:45 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:46 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stk_find(t_stack *stk, t_stack *stk_to_find)
{
	while (stk)
	{
		if (stk->next == stk_to_find)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}

void	print_stk(t_stack *lst)
{
	t_stack	*current;

	current = lst;
	ft_putstr_fd("°°°°°°°\n", 1);
	while (current)
	{
		ft_putnbr_fd(current->number, 1);
		ft_putchar_fd('\n', 1);
		current = current->next;
	}
	ft_putstr_fd("°°°°°°°\n", 1);
}

void	free_after_split(char **tab)
{
	long	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}
