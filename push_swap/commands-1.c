/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:05:24 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:05:25 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src, char *str)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
	ft_putstr_fd(str, 1);
}

void	swap(t_stack **head, char *str)
{
	t_stack	*first;
	t_stack	*second;

	if (!*head || !(*head)->next)
		return ;
	first = (*head)->next;
	second = *head;
	second->prev = first;
	second->next = first->next;
	if (first->next)
		first->next->prev = second;
	first->next = first->prev;
	first->prev = NULL;
	*head = first;
	ft_putstr_fd(str, 1);
}

void	rotate(t_stack **head, char *str)
{
	t_stack	*last;

	if (!*head || !((*head)->next))
		return ;
	last = stk_last(*head);
	last->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	ft_putstr_fd(str, 1);
}

void	reverse_rotate(t_stack **head, char *str)
{
	t_stack	*last;

	if (!*head || !((*head)->next))
		return ;
	last = stk_last(*head);
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	last->next->prev = last;
	ft_putstr_fd(str, 1);
}
