/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:08:56 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:08:56 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	s_len;
	size_t			i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (len > (s_len - start))
		len = s_len - start;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>

// int main(void)
// {
// 	char const *s = "tripouille";
// 	unsigned int start = 42;
// 	size_t len = 42000000;
// 	char * ret;

// 	ret = ft_substr(s, start, len);
// 	printf("|%s|\n", ret);
// 	// ret = ft_strnstr(haystack, "abcd", 19);
// 	// printf("|%s|\n", ret);
// 	return (0);
// }
