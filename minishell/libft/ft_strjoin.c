/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frobain <frobain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:07:58 by frobain           #+#    #+#             */
/*   Updated: 2023/11/10 17:09:58 by frobain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined;
	unsigned int	i;
	unsigned int	j;
	unsigned int	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(total_size + 1);
	i = 0;
	j = 0;
	if (!joined)
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
// int	main(void)
// {
// 	printf("Resultat du join : %s", ft_strjoin("Je veux merge ca",
// 			" avec ca svp"));
// }