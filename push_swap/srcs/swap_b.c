/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:57:34 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 19:30:04 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap_b(t_list **b)
{
	t_list	*first;
	t_list	*second;
	void	*temp;

	if (*b && (*b)->next)
	{
		first = *b;
		second = (*b)->next;
		temp = first->content;
		first->content = second->content;
		second->content = temp;
	}
}
