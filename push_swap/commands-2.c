/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands-2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:05:31 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:05:32 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
	{
		rotate(a, "");
		rotate(b, "rr\n");
	}
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
	{
		reverse_rotate(a, "");
		reverse_rotate(b, "rrr\n");
	}
	current_index(*a);
	current_index(*b);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate(stack, "ra\n");
			else
				reverse_rotate(stack, "rra\n");
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate(stack, "rb\n");
			else
				reverse_rotate(stack, "rrb\n");
		}
	}
}
