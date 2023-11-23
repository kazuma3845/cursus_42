/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:07:58 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 15:53:11 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstprint(t_stack_a *a)
{
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_a a;

	if (argc < 2)
		return (0);
	// if (error_arg() == 1)
	// 	return (write(1, "Error\n", 6));
	a = ft_lstnew();
	ft_lstprint(&a);
	return (0);
}
