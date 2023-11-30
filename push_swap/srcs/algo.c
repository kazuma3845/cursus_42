/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:38:59 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/30 12:04:22 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

int	reach(t_list **b)
{
	int	max;

	max = nbr_max(b);
	if (max == 1)
		return (1);
	return (0);
}

void	test2(t_list **b)
{
	if (reach(b) == 1)
		swap_b(b, 0);
	else
		rotate_b(b, 0);
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
			while (max != ++i)
				test2(b);
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
