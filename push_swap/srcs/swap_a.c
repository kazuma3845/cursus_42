/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:57:09 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 19:29:52 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*first;
	t_list	*second;
	void	*temp;

	if (*a && (*a)->next)
	{
		first = *a;
		second = (*a)->next;
		temp = first->content;
		first->content = second->content;
		second->content = temp;
	}
}
