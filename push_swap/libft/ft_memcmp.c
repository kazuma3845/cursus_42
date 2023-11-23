/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:45:15 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:27 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*l1;
	unsigned char	*l2;

	l1 = (unsigned char *)s1;
	l2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((*l1 == *l2) && n - 1 > 0)
	{
		l1++;
		l2++;
		n--;
	}
	return ((int)(*l1 - *l2));
}
