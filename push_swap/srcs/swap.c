/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:57:09 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/24 12:06:58 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap_a(t_list **a, int i)
{
	t_list	*first;
	t_list	*second;
	void	*temp;

	if (*a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		temp = first->content;
		first->content = second->content;
		second->content = temp;
	}
	if (i == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **b, int i)
{
	t_list	*first;
	t_list	*second;
	void	*temp;

	if (*b && (*b)->next)
	{
		first = *b;
		second = (*b)->next;
		temp = first->content;
		first->content = second->content;
		second->content = temp;
	}
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap_a(a, 1);
	swap_b(b, 1);
	write(1, "ss\n", 3);
}
