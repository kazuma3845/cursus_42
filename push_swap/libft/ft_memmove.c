/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:48:29 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:46:33 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			j;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	j = 1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst > src)
	{
		j = -1;
		d += len - 1;
		s += len - 1;
	}
	while (i < len)
	{
		*d = *s;
		d += j;
		s += j;
		i++;
	}
	return (dst);
}
