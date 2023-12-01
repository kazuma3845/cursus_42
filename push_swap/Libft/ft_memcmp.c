/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:11:15 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:11:16 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*ptr_s1;
	unsigned char		*ptr_s2;
	unsigned int		i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(){

// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	int ret;

// 	ret = ft_memcmp(s, sCpy, 4);
// 	printf("|%i|\n", ret);
// 	ret = ft_memcmp(s, s2, 0);
// 	printf("|%i|\n", ret);
// 	ret = ft_memcmp(s, s2, 1);
// 	printf("|%i|\n", ret);
// 	ret = ft_memcmp(s2, s, 1);
// 	printf("|%i|\n", ret);
// 	ret = ft_memcmp(s2, s3, 4);
// 	printf("|%i|\n", ret);

// 	return(0);
// }