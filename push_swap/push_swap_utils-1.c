/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils-1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:06:39 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:40 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stk_sorted(t_stack *stack)
{
	if (!(stack))
		return (1);
	while ((stack)->next)
	{
		if ((stack)->number > stack->next->number)
		{
			return (false);
		}
		(stack) = (stack)->next;
	}
	return (true);
}

t_stack	*stk_max(t_stack *stk)
{
	long	max;
	t_stack	*max_stk;

	if (!stk)
		return (NULL);
	max = LONG_MIN;
	while (stk)
	{
		if (stk->number > max)
		{
			max = stk->number;
			max_stk = stk;
		}
		stk = stk->next;
	}
	return (max_stk);
}

t_stack	*stk_min(t_stack *stk)
{
	long	min;
	t_stack	*min_stk;

	if (!stk)
		return (NULL);
	min = LONG_MAX;
	while (stk)
	{
		if (stk->number < min)
		{
			min = stk->number;
			min_stk = stk;
		}
		stk = stk->next;
	}
	return (min_stk);
}

t_stack	*stk_last(t_stack *stk)
{
	while (stk)
	{
		if (!stk->next)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}

int	stk_size(t_stack *stk)
{
	size_t	i;

	i = 0;
	while (stk)
	{
		stk = stk->next;
		i++;
	}
	return (i);
}
