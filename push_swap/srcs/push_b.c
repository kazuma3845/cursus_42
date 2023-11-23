/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:58:17 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 19:11:10 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		ft_lstadd_front(a, ft_lstnew((*b)->content));
		temp = *b;
		*b = (*b)->next;
		free(temp);
	}
}
