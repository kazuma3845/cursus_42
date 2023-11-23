/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:28:27 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:36 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*a;

	i = 0;
	a = b;
	while (i < len)
	{
		a[i] = c;
		i++;
	}
	return (a);
}
