/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:07:58 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/30 11:54:08 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	contains_letter(const char *str)
{
	while (*str)
	{
		if (ft_isalnum(*str) || *str == '-' || *str == '+' || *str == ' ')
			str++;
		else
			return (1);
	}
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (contains_letter(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	init_list(int argc, char **argv, t_list **a)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) > 2)
		{
			str = ft_split(argv[1], ' ');
			while (str[j])
				j++;
			while (i != j)
			{
				ft_lstadd_back(a, ft_lstnew(ft_atoi(str[i])));
				free(str[i++]);
			}
			free(str);
		}
	}
	else
		while (++i < argc)
			ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
	return (0);
}

int	check(t_list **a)
{
	t_list	*check;

	check = *a;
	while (check && check->next)
	{
		if (check->content > check->next->content)
			return (0);
		check = check->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	if (argc < 2)
		return (0);
	if (init_list(argc, argv, &a) == 1 || check_arguments(argc, argv) == 1)
	{
		free_liste(&a);
		return (ft_printf("Error\n"));
	}
	if (check(&a) != 1 || ft_lstsize(a) == 1)
	{
		if (error(&a) == 1)
		{
			free_liste(&a);
			return (ft_printf("Error\n"));
		}
		algo(&a, &b);
		if_is_3(&a);
		test(&a, &b);
	}
	// ft_lstprint(&a);
	free_liste(&a);
	return (0);
}
