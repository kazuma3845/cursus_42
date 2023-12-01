/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:09:57 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:09:58 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	s1_size;
	unsigned int	s2_size;
	unsigned int	i;

	if (!s1 && !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = malloc (sizeof(char) * (s1_size + s2_size + 1));
	if (!result)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[i - s1_size] != '\0')
	{
		result[i] = s2[i - s1_size];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	const char	*s1 = "1234";
// 	const char	*s2 = "5678";
// 	char		*result;

// 	result= ft_strjoin(s1, s2);
// 	printf("%s\n", result);
// 	free(result);
// }