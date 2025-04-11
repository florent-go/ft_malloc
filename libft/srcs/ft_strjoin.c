/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:57 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/23 13:01:17 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_ldlc(char const *s1, char const *s2)
{
	int		ldlc;

	ldlc = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	return (ldlc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!(dest = malloc(sizeof(char) * ft_ldlc(s1, s2))))
		return (NULL);
	dest[0] = '\0';
	ft_strcpy(dest, (char *)s1);
	ft_strcat(dest, (char *)s2);
	return (dest);
}
