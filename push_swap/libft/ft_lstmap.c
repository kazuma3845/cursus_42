/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:10:19 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:16 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
