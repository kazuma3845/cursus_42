/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomuller <tomuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:10:22 by tomuller          #+#    #+#             */
/*   Updated: 2023/12/01 12:10:23 by tomuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_strs(char const *str, char c)
{
	int	i;
	int	strs;

	i = 0;
	strs = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i - 1] != c && i > 0)
			strs++;
	}
	return (strs);
}

size_t	str_len(char const *s, char c, unsigned int i)
{
	unsigned int	size;

	size = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

void	free_array(int i_w, char **tab)
{
	while (i_w > 0)
	{
		i_w--;
		free(tab[i_w]);
	}
	free(tab);
}

char	**create_split(char const *s, char c, unsigned int word_q, char **tab)
{
	unsigned int	i_w;
	unsigned int	i_c;

	i_w = 0;
	i_c = 0;
	while (i_w < word_q)
	{
		while (s[i_c] == c && s[i_c] != '\0')
			i_c++;
		tab[i_w] = ft_substr(s, i_c, str_len(s, c, i_c));
		if (!tab[i_w])
		{
			free_array(i_w, tab);
			return (0);
		}
		while (s[i_c] != c && s[i_c] != '\0')
			i_c++;
		i_w++;
	}
	tab[i_w] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	word_q;
	char			**tab;

	if (!s)
		return (0);
	word_q = count_strs(s, c);
	tab = (char **) malloc(sizeof(char *) * (word_q + 1));
	if (!tab)
		return (NULL);
	tab = create_split(s, c, word_q, tab);
	return (tab);
}

//---------------------------------------------------------------------------

// int main ()
// { 
// 	const char	str[] = "yy123y3456yy85673233y";
// 	const char	ch = 'y';
// 	char		**ret;
// 	int			index;

// 	index = 0;
// 	ret = ft_split(str, ch);
// 	while (ret[index])
// 	{
// 		printf("%s\n", ret[index]);
// 		index++;
// 	}
// 	return(0);
// }
