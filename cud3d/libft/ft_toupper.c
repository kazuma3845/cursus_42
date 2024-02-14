/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:16:34 by neah              #+#    #+#             */
/*   Updated: 2023/11/10 17:10:31 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int	main(void)
// {
// 	char lower = 'a';
// 	char upper = ft_toupper(lower);
// 	printf("Majuscule: %c, Minuscule: %c\n", lower, upper);
// }
