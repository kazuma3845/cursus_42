/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:07:58 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/28 17:12:56 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	error_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = i + 1;
		while (j != argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atoi(char *str)

{
	int i;
	int j;
	long retourn;

	i = 0;
	j = 1;
	retourn = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i]) 
	{
		retourn *= 10;
		retourn += str[i] - '0';
		i++;
	}
	return (retourn * j);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	i = 1;
	b = NULL;
	if (argc < 2)
		return (0);
	// if (error_arg(argc, argv) == 1)
	// 	return (write(1, "Error\n", 6));
	while (i != argc)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	algo(&a, &b);
	if_is_3(&a, &b);
	test(&a, &b);
	// ft_lstprint(&a);
	// ft_lstprint(&b);
	return (0);
}
