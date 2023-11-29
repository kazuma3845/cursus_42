/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:57:24 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/29 14:17:20 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_remove_nodes(t_list **a)
{
	t_list	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = temp->next;
	free(temp);
}

void	ft_remove_nodes_last(t_list **a)
{
	t_list	*current;
	t_list	*previous;

	if (*a == NULL)
		return ;
	current = *a;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	if (previous == NULL)
	{
		free(current);
		*a = NULL;
	}
	else
	{
		free(previous->next);
		previous->next = NULL;
	}
}

void	ft_lstprint(t_list **head)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		ft_printf("\n%d", current->content);
		current = current->next;
	}
	ft_printf("\n\n%d\n\n", ft_lstsize(*head));
}

void	free_liste(t_list **a)
{
	while (*a)
		ft_remove_nodes(a);
}
