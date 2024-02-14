/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:39:00 by frobain           #+#    #+#             */
/*   Updated: 2023/11/15 12:27:33 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if ((unsigned char)*s == c)
			last_occurrence = s;
		s++;
	}
	return ((char *)last_occurrence);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("upper", 'p'));
// 	printf("%s", strrchr("upper", 'p'));
// }