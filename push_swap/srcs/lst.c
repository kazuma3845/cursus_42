/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:41:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/27 15:52:48 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*ft_lstnew(long content)
{
	t_list	*tab;

	tab = (t_list*)malloc(sizeof(t_list));
	if (tab == NULL)
		return (0);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*tab;

	i = 0;
	tab = lst;
	while (tab != NULL)
	{
		tab = tab->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tab;

	tab = lst;
	if (lst == NULL)
		return (0);
	while (tab->next != NULL)
		tab = tab->next;
	return (tab);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst != NULL)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
