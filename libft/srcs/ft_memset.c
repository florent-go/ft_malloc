/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:44:08 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/20 08:30:31 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;

	ch = (unsigned char*)b;
	while (len)
	{
		*ch = (unsigned char)c;
		ch++;
		len--;
	}
	return (b);
}
