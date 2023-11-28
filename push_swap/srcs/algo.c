/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:38:59 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/28 17:00:38 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// If a = 3
// If a = 4
// If a = 5

int	ft_count(t_list **a, t_list *check)
{
	t_list	*current;
	int		count;

	count = 0;
	current = *a;
	while (current != NULL)
	{
		if (current->content < check->content)
			count++;
		current = current->next;
	}
	return (count);
}

void	algo(t_list **a, t_list **b)
{
	int	len;
	int	count;
	int	len_total;

	len_total = ft_lstsize(*a);
	while (len_total > 3)
	{
		len = 0;
		while (len < len_total / 2)
		{
			count = ft_count(a, *a);
			if (count + len < len_total / 2)
			{
				push_a(a, b);
				len++;
			}
			else
				rotate_a(a, 0);
		}
		len_total = ft_lstsize(*a);
	}
}

void	if_is_3(t_list **a, t_list **b)
{
	int		count;
	t_list	*check;

	check = *a;
	count = ft_count(a, *a);
	if (count == 2)
	{
		rotate_a(a, 0);
		if ((*a)->content > (*a)->next->content
			&& (*b)->content < (*b)->next->content)
			ss(a, b);
		else if ((*b)->content < (*b)->next->content)
			swap_b(b, 0);
		if ((*a)->content > (*a)->next->content)
			swap_a(a, 0);
	}
	else if (count == 1)
	{
		if ((*a)->content > (*a)->next->content)
			swap_a(a, 0);
		else
			reverse_rotate_a(a, 0);
	}
	else if (count == 0)
	{
		check = check->next;
		if (check->next == NULL)
			return ;
		if (check->content > check->next->content)
		{
			rotate_a(a, 0);
			swap_a(a, 0);
			reverse_rotate_a(a, 0);
		}
	}
}

int	nbr_max(t_list **b)
{
	t_list	*check;
	int		max;
	int		nbr;
	int		i;

	max = 0;
	i = 0;
	nbr = (*b)->content;
	check = *b;
	check = check->next;
	while (check)
	{
		i++;
		if (check->content > nbr)
		{
			nbr = check->content;
			max = i;
		}
		check = check->next;
	}
	return (max);
}

void	test(t_list **a, t_list **b)
{
	int	len_max;
	int	i;
	int	max;

	while (*b)
	{
		i = -1;
		len_max = ft_lstsize(*b);
		max = nbr_max(b);
		if (max <= (len_max / 2))
		{
			if (max != 0)
			{
				while (max != ++i)
					rotate_b(b, 0);
			}
		}
		else
		{
			max = len_max - max;
			while (max != ++i)
				reverse_rotate_b(b, 0);
		}
		push_b(a, b);
	}
}
