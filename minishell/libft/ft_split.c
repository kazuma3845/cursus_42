/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neah <neah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:51:04 by neah              #+#    #+#             */
/*   Updated: 2024/01/25 11:20:12 by neah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char del)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != del && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == del)
			in_word = 0;
		i++;
	}
	return (count);
}

char	**ft_free_split(char **split, int j)
{
	while (j > 0)
	{
		free(split[j - 1]);
		j--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] && j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		split[j] = ft_substr(s, start, i - start);
		if (!split[j])
			return (ft_free_split(split, j));
		j++;
	}
	split[j] = NULL;
	return (split);
}

// int	main(void)
// {
// 	char **words = ft_split("ceci est une phrase de test", ' ');
// 	if (words == NULL)
// 	{
// 		printf("Erreur de mémoire\n");
// 		return (1);
// 	}

// 	for (int i = 0; i < ft_count_words("ceci est une phrase de test", ' '); ++i)
// 	{
// 		printf("Mot %d : %s\n", i + 1, words[i]);
// 		free(words[i]);
// 	}
// 	free(words);

// 	return (0);
// }