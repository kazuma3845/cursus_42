/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:04 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:09:04 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	while (check_char(s1[start], set) == 1 && start < end)
		start++;
	while (end > 0 && check_char(s1[end - 1], set) == 1 && start < end)
		end--;
	trim = malloc(sizeof(char) * ((end - start) + 1));
	if (!trim || !s1 || !set)
		return (0);
	i = 0;
	while (start + i < end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

// #include <stdio.h>

// int main(void)
// {
// 	char const *s1 = "   xx xxx";
// 	char const *set = " xt";
// 	char * ret;
// 	ret = ft_strtrim(s1, set);
// 	printf("|%s|\n", ret);

// 	return (0);
// }
