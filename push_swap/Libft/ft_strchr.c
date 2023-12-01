/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:10:17 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:10:18 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)0);
}

// #include <stdio.h>

// int main ()
// { 
//    const char str[] = "tripouille";
//    const char ch = 'p';
//    char *ret;

//    ret = ft_strchr(str, ch + 256);

//    printf("String after |%c| is - |%s|\n", ch, ret);

//    return(0);
// }