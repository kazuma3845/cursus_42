/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:26:02 by frobain           #+#    #+#             */
/*   Updated: 2023/11/10 17:10:27 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
// int	main(void)
// {
// 	char upper = 'A';
// 	char lower = ft_tolower(upper);
// 	printf("Majuscule: %c, Minuscule: %c\n", upper, lower);
// }