/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neah <neah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:27:31 by frobain           #+#    #+#             */
/*   Updated: 2023/11/13 12:34:27 by neah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	lf;

	lf = (char)c;
	while (*s)
	{
		if (*s == lf)
			return ((char *)s);
		s++;
	}
	if (lf == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
//
// 	printf("%s\n", ft_strchr("upper", 'p'));
// 	printf("%s", strchr("upper", 'p'));
// }