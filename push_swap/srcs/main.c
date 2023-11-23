/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:07:58 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 14:40:22 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	// if (error_arg() == 1)
	// 	return (write(1, "Error\n", 6));
	printf("%c", *argv[1]);
	return (0);
}
