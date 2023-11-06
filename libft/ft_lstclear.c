/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:31:13 by tomuller          #+#    #+#             */
/*   Updated: 2023/10/30 13:04:13 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
