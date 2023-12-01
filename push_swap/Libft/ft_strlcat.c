/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:46 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:09:49 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dstlen;
	unsigned int	j;

	dstlen = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && (dstlen + j + 1) < dstsize)
	{
		dst[dstlen + j] = src[j];
		j++;
	}
	dst[dstlen + j] = '\0';
	if (dstsize > dstlen)
		return (dstlen + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}

// #include <stdio.h>

// int main(){
// 	const char src[50] = "lorem ipsum doloertr sit amet";
// 	char dest[14] = "a";
// 	unsigned int result = 0;
// 	printf("Before memcpy dest = %s\n", dest);
// 	result = ft_strlcat(dest, src, 15);
// 	printf("After memcpy dest = %i\n", result);

// 	return(0);
// }

// unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	while (dst[i] != '\0')
// 		i++;
// 	j = 0;
// 	while (src[j] != '\0' && (i + j + 1) < dstsize)
// 	{
// 		dst[i + j] = src[j];
// 		j++;
// 	}
// 	dst[i + j] = '\0';
// 	if (dstsize > i)
// 		return (i + ft_strlen((char *)src));
// 	else
// 		return (dstsize + ft_strlen((char *)src));
// }
