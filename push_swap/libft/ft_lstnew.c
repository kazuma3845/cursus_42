/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:48:44 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:19 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	tab = malloc(sizeof (t_list));
	if (tab == NULL)
		return (0);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}
