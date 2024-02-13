/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neah <neah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:53:58 by frobain           #+#    #+#             */
/*   Updated: 2023/11/13 10:41:18 by neah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		idx;

	if (!src && !dst && len > 0)
		return (NULL);
	dest = (char *)dst;
	source = (const char *)src;
	if (dest > source)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else
	{
		idx = 0;
		while (idx < len)
		{
			dest[idx] = source[idx];
			idx++;
		}
	}
	return (dst);
}

// int main()
// {
//     char str[] = "Exemple de memmove";

//
// On déplace une partie de la chaîne sur elle-même avec un chevauchement.
//     printf("Avant memmove: %s\n", str);
//     ft_memmove(str+8, str+3, 10);
//     printf("Après memmove: %s\n", str);

//     return (0);
// }