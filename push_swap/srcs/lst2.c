/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:57:24 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/24 12:43:48 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_remove_null_nodes(t_list **head)
{
	if (!head || !*head)
		return ;

	t_list *current = *head, *prev = NULL;

	while (current)
	{
		if (current->content == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;

			t_list *temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	ft_lstprint(t_list **head)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		ft_printf("%s\n", current->content);
		current = current->next;
	}
	ft_printf("\n%d\n\n", ft_lstsize(*head));
}
