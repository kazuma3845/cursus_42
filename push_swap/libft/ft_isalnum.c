/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:59:37 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 13:45:40 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c <= 90 && c >= 65) || (c <= 122 && c >= 97))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main()
{
    int num = 47;
    printf("%d", ft_isalnum(num));
    return (0);
}*/