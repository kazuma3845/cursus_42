/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:47:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:22 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
