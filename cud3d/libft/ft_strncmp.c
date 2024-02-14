/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neah <neah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:48:27 by frobain           #+#    #+#             */
/*   Updated: 2023/11/13 14:32:43 by neah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*src;
	unsigned char	*dest;

	i = 0;
	src = (unsigned char *)s1;
	dest = (unsigned char *)s2;
	while (i < n && src[i] && dest[i] && src[i] == dest[i])
		i++;
	if (i < n)
		return ((int)src[i] - dest[i]);
	return (0);
}

// int	main(void)
// {
// 	printf("%d \n", ft_strncmp("Hella", "Hello", 6));
// 	printf("%d", strncmp("Hella", "Hello", 6));
// }