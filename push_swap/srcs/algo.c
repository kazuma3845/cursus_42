/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:38:59 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 11:30:47 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	val_min(t_list **b)
{
	t_list	*check;
	int		min;

	check = *b;
	min = check->content;
	while (check)
	{
		if (check->content < min)
			min = check->content;
		check = check->next;
	}
	return (min);
}

int	val_max(t_list **b)
{
	t_list	*check;
	int		max;

	check = *b;
	max = check->content;
	while (check)
	{
		if (check->content > max)
			max = check->content;
		check = check->next;
	}
	return (max);
}

int	checker(t_list **a, t_list **b)
{
	t_list	*check_prev;
	t_list	*check_next;

	check_next = (*b);
	check_prev = ft_lstlast(*b);
	if (((*a)->content > check_next->content
			&& (*a)->content < check_prev->content)
		|| ((*a)->content > val_max(b) && val_max(b) == check_next->content)
		|| ((*a)->content < val_min(b) && val_min(b) == check_prev->content))
		return (0);
	return (1);
}

void	if_is_3_inv(t_list **a)
{
	int		count;
	t_list	*check;

	check = (*a)->next;
	count = ft_count(a, *a);
	if (count == 2)
	{
		reverse_rotate_b(a, 0);
		if ((*a)->content < (*a)->next->content)
			swap_b(a, 0);
	}
	else if (count == 1)
	{
		if ((*a)->content < (*a)->next->content)
			swap_b(a, 0);
		else
			rotate_b(a, 0);
	}
	else if (count == 0)
	{
		if (check->content < check->next->content)
		{
			reverse_rotate_b(a, 0);
			swap_b(a, 0);
			rotate_b(a, 0);
		}
	}
}

int	ft_index(t_list **a, t_list **b)
{
	t_list	*check_prev;
	t_list	*check_next;
	int		i;

	i = 0;
	check_next = (*b);
	check_prev = ft_lstlast(*b);
	while (((*a)->content < check_next->content && (*a)->content > check_prev->content) || ((*a)->content < val_max(&check_next) && val_max(&check_next) == check_next->content) || ((*a)->content > val_min(&check_next) && val_min(&check_next) == check_prev->content))
	{
		reverse_rotate_a(&check_next, 1);
		check_prev = ft_lstlast(check_next);
		i++;
	}
	return (i);
}

void	algo(t_list **a, t_list **b)
{
	int		len_total;
	t_list	*check;
	// int	i;

	len_total = ft_lstsize(*a);
	if (len_total > 3)
	{
		push_a(a, b);
		push_a(a, b);
		push_a(a, b);
		len_total -= 2;
	}
	if_is_3_inv(b);
	while (--len_total > 3)
	{
		//  i = ft_index(a, b);
		while (checker(a, b) == 1)
		{
			// if (i < (ft_lstsize(*b) / 2))
			// 	rotate_b(b, 0);
			// else
				reverse_rotate_b(b, 0);
		}
		push_a(a, b);
	}
	if_is_3(a);
	while ((*b)->content != val_max(b))
		rotate_b(b, 0);
	while (*b)
	{
		check = ft_lstlast(*a);
		if (((*b)->content > check->content || ((*b)->content < val_min(a) && val_min(a) == (*a)->content)))
			push_b(a, b);
		else if (ft_lstsize(*b) > 0)
			reverse_rotate_a(a, 0);
	}
	while ((*a)->content != val_min(a))
		reverse_rotate_a(a, 0);
	// ft_lstprint(a);
	// ft_lstprint(b);
}
