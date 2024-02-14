/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:39:51 by frobain           #+#    #+#             */
/*   Updated: 2023/11/10 17:27:21 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len-- > 0)
	{
		*a = (unsigned char)c;
		a++;
	}
	return (b);
}

// int main() {
//     char buffer[10];

//     ft_memset(buffer, 'A', sizeof(buffer) - 1);
//     buffer[9] = '\0';
//     printf("ft_memset result: %s", buffer);
// }