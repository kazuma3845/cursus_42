/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:11:11 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:11:12 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	unsigned const char	*ptr_src;

	if (!dst && !src)
		return (0);
	ptr_dst = dst;
	ptr_src = src;
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}

// #include <stdio.h>

// int main(){
// 	const char src[50] = "";
// 	char dest[50] = "Heloooo!!";
// 	printf("Before memcpy dest = %s\n", dest);
// 	ft_memcpy(dest, src, 5);
// 	printf("After memcpy dest = %s\n", dest);

// 	return(0);
// }
