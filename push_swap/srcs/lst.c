/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:41:10 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 17:43:06 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	tab = malloc(sizeof(t_list));
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tab;
	t_list	*n;

	if (lst == NULL || f == NULL)
		return (0);
	n = NULL;
	while (lst != NULL)
	{
		tab = ft_lstnew(f(lst->content));
		if (tab == NULL)
		{
			ft_lstclear(&tab, (*del));
			return (0);
		}
		ft_lstadd_back(&n, tab);
		lst = lst->next;
	}
	return (n);
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

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tab;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tab = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tab;
	}
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
