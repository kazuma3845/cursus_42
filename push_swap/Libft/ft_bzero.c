/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:12:24 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:12:24 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = '\0';
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char *str = argv[1];
// 	(void)argc;
// 	ft_bzero(str, 3);
// 	printf("sdfhsd");
// 	printf("%s dfg", str);
// 	return (0);
// }