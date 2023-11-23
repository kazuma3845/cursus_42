/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:52:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:45:34 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;

	tab = malloc(size * count);
	if (tab == NULL)
		return (0);
	ft_bzero(tab, (count * size));
	return (tab);
}
