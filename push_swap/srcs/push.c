/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:58:05 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/27 16:20:15 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void push_a(t_list **a, t_list **b)
{
    if (*a != NULL)
    {
        ft_lstadd_front(b, ft_lstnew((*a)->content));
        *a = (*a)->next;
    }
    write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	if (*b)
	{
		ft_lstadd_front(a, ft_lstnew((*b)->content));
		*b = (*b)->next;
	}
	write(1, "pb\n", 3);
}
