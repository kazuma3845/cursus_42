/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:58:05 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 19:22:35 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a)
	{
		ft_lstadd_front(b, ft_lstnew((*a)->content));
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
}
