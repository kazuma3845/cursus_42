/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:30 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/24 12:17:42 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	reverse_rotate_a(t_list **a, int i)
{
	t_list	*last;

	last = ft_lstlast(*a);
	ft_lstadd_front(a, ft_lstnew(last->content));
	last->content = NULL;
	ft_remove_null_nodes(a);
	if (i == 0)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **b, int i)
{
	t_list	*last;

	last = ft_lstlast(*b);
	ft_lstadd_front(b, ft_lstnew(last->content));
	last->content = NULL;
	ft_remove_null_nodes(b);
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate_a(a, 1);
	reverse_rotate_b(b, 1);
	write(1, "rrr\n", 4);
}
