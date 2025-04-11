/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:24:38 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/25 12:12:53 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char*)dest = *(char*)src;
		i++;
		src++;
		dest++;
	}
	return (dst);
}
