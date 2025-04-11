/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:29:45 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/25 12:54:17 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long int	ft_abs(long int nbr)
{
	if (nbr < 0)
	{
		return (-nbr);
	}
	return (nbr);
}

int			ft_len(long int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}

void ft_itoa_base(size_t nb, char base, char lenght)
{
    char 	*str;
	bool 	prefixe;

	prefixe = false;
	if (base == 16)
		prefixe = true;
    str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (nb/base)
        ft_itoa_base(nb/base, base,lenght-1);
    else
    {
        if (prefixe)
            ft_putstr("0x");
        while(--lenght > 0)
        {
            ft_putstr("0");
        }
    }
    write(1, &str[nb % base], 1);
}