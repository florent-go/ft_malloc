/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:15:07 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/25 11:43:47 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen((char *)s2);
	while (*s1 != '\0' && n-- >= len)
	{
		if (*s1 == *s2 && ft_strncmp((char *)s1, (char *)s2, len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
