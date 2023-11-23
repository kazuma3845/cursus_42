/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:06:58 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:13 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
