/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:25:00 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/21 15:18:20 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (i++ < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
