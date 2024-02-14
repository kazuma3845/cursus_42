/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:47:13 by frobain           #+#    #+#             */
/*   Updated: 2023/11/10 17:10:02 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (src[i])
		i++;
	k = 0;
	while (dst[k] && k < dstsize)
		k++;
	j = 0;
	if (k < dstsize)
	{
		while (src[j] && j + k < dstsize - 1)
		{
			dst[j + k] = src[j];
			j++;
		}
		dst[j + k] = '\0';
	}
	return (i + k);
}
// int	main(void)
// {
// 	char dest[10] = "Test";
// 	const char *source = "A copier";

// 	printf("Longueur retourne : %zu", ft_strlcat(dest, source, 10));
// }