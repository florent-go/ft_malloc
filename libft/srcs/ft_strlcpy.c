/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:25:05 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/21 14:42:48 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] && i < n)
		i++;
	while (src[j] && j + 1 < n)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
		dest[j] = '\0';
	return (ft_strlen((char *)src));
}
