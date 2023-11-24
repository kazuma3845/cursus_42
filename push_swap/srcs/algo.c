/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:38:59 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/24 13:19:46 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	algo(t_list **a, t_list **b)
{
	int	nbr_node;
	int i;
	t_list *current;
 
	i = 0;
	current = *a;
	nbr_node = ft_lstsize(*a);
	while (i != nbr_node / 2)
	{
		if (current->content < current->next->content)
		{
			push_a(a, b);
			i++;
		}
		else
			swap_a(a, 0);
	}
}
