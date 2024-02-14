/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:17:54 by neah              #+#    #+#             */
/*   Updated: 2023/11/15 12:26:24 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

// int main() {
//     const char *str = "Hello World";
//     char c = 'z';
//     char *ptr = ft_memchr(str, c, sizeof(str));
//     if (ptr) {
//         printf("Le byte '%c' trouvé à l'adresse: %p\n", c, ptr);
//     } else {
//         printf("Le byte '%c' n'a pas été trouvé\n", c);
//     }
//     return (0);
// }