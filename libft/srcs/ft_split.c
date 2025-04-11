/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:53:18 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/23 12:00:38 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		is_c(char index, char c)
{
	if (index == c)
		return (1);
	return (0);
}

int		count_charc(char const *s, char c)
{
	int charc;
	int i;

	charc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && is_c(s[i], c) == 1)
			i++;
		if (s[i] && is_c(s[i], c) == 0)
		{
			charc++;
			while (s[i] && is_c(s[i], c) == 0)
				i++;
		}
	}
	return (charc);
}

char	*ft_malloc(char const *s, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (s[i] && is_c(s[i], c) == 0)
		i++;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && is_c(s[i], c) == 0)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;

	i = count_charc(s, c);
	j = 0;
	if (!(dest = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[j])
	{
		while (s[j] && is_c(s[j], c) == 1)
			j++;
		if (s[j] && is_c(s[j], c) == 0)
		{
			dest[i] = ft_malloc((s + j), c);
			i++;
			while (s[j] && is_c(s[j], c) == 0)
				j++;
		}
	}
	dest[i] = NULL;
	return (dest);
}
