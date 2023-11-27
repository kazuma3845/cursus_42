/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:38:59 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/27 17:17:35 by tomuller         ###   ########.fr       */
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
	while (len_total > 5)
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

void	if_is_3(t_list **a)
{

}

void	if_is_4(t_list **a)
{

}

void	if_is_5(t_list **a)
{

}
