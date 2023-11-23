/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:07:58 by tomuller          #+#    #+#             */
/*   Updated: 2023/11/23 19:30:10 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstprint(t_list **head)
{
	t_list *current;

	current = *head;
	while (current)
	{
		ft_printf("%s\n", current->content);
		current = current->next;
	}
	ft_printf("\n%d\n", ft_lstsize(*head));
}

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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	i = 1;
	b = NULL;
	if (argc < 2)
		return (0);
	if (error_arg(argc, argv) == 1)
		return (write(1, "Error\n", 6));
	while (i != argc)
	{
		ft_lstadd_back(&a, ft_lstnew(argv[i]));
		i++;
	}
	// algo(&a, &b);
	ft_lstprint(&a);
	ft_lstprint(&b);
	return (0);
}
