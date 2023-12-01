/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:06:27 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:06:27 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || (argc == 2 && argv[1][0] == 0))
		return (1);
	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv);
		free_after_split(argv);
	}
	else
		init_stack_a(&a, argv + 1);
	find_algo(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
