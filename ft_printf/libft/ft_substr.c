/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:46:13 by tomuller          #+#    #+#             */
/*   Updated: 2023/10/27 09:49:17 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s);
	j = 0;
	if (s == NULL)
		return (0);
	if (i < start)
	{
		len = 0;
		start = 0;
	}
	if (i > start)
		j = i - start;
	if (j > len)
		j = len;
		str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s + start, j + 1);
	return (str);
}
