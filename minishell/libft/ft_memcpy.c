/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:46:25 by frobain           #+#    #+#             */
/*   Updated: 2023/11/15 09:51:25 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*source;
	char	*dest;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (0);
	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	const char *str = "Aello World";
// 	const char *str2[30];

// 	printf("Difference de %s\n", ft_memcpy(str2, str, sizeof(str)));
// }