/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:58:45 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/27 15:17:08 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate_a(t_list **a, int i)
{
	t_list	*first;

	first = *a;
	ft_lstadd_back(a, ft_lstnew(first->content));
	ft_remove_nodes(a);
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **b, int i)
{
	t_list	*first;

	first = *b;
	ft_lstadd_back(b, ft_lstnew(first->content));
	ft_remove_nodes(b);
	if (i == 0)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate_a(a, 1);
	rotate_b(b, 1);
	write(1, "rr\n", 3);
}
