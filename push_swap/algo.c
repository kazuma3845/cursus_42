/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:05:06 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:05:07 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duo_algo(t_stack **a)
{
	swap(a, "sa\n");
}

void	trio_algo(t_stack **a)
{
	if (*a == stk_max(*a))
		rotate(a, "ra\n");
	if ((*a)->next == stk_max(*a))
		reverse_rotate(a, "rra\n");
	if ((*a) != stk_min(*a))
		swap(a, "sa\n");
}

void	multi_algo(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stk_size(*a);
	if (len_a-- > 3 && !stk_sorted(*a))
		push(b, a, "pb\n");
	if (len_a-- > 3 && !stk_sorted(*a))
		push(b, a, "pb\n");
	while (len_a-- > 3 && !stk_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	trio_algo(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	set_order(a);
}

void	find_algo(t_stack **a, t_stack **b)
{
	if (!stk_sorted(*a))
	{
		if (stk_size(*a) == 2)
			duo_algo(a);
		else if (stk_size(*a) == 3)
			trio_algo(a);
		else if (stk_size(*a) > 3)
			multi_algo(a, b);
	}
}
