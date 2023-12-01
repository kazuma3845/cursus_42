/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:10:52 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:10:53 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char *str = argv[1];
// 	(void)argc;
// 	printf("%s", ft_memset(str, 'F', 3));
// 	return (0);
// }