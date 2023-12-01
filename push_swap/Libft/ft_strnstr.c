/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:16 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:09:17 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ne, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(ne) <= 0)
		return ((char *)hs);
	while (hs[i] != '\0' && i < len)
	{
		j = 0;
		while (hs[i + j] == ne[j] && i + j < len)
		{
			if (ne[j + 1] == '\0')
				return ((char *)hs + i);
			j++;
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	char * ret;

// 	ret = ft_strnstr(haystack, needle, -1);
// 	printf("|%s|\n", ret);
// 	ret = ft_strnstr(haystack, "abcd", 19);
// 	printf("|%s|\n", ret);
// 	return (0);
// }
