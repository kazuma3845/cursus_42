/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:24:30 by tomuller          #+#    #+#             */
/*   Updated: 2023/10/26 10:17:52 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*a;
	const unsigned char	*b;

	i = 0;
	a = dst;
	b = src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i != n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
/*
#include <stdio.h>

int main()
{
    char src[] = "Hello, World!";
    char dest[20];
    
    ft_memcpy(dest, src, 0);
    
    printf("%s", dest);

    return 0;
}*/
