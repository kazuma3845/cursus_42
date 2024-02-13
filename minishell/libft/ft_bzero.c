/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:57:27 by frobain           #+#    #+#             */
/*   Updated: 2023/11/10 17:09:01 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (n-- > 0)
	{
		*a = 0;
		a++;
	}
}
// int main() {
//     char buffer[10];

//     ft_bzero(buffer, sizeof(buffer) - 1);
//     printf("ft_bzero result: %s", buffer);
// }