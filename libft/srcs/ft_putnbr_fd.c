/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:27:34 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/20 14:56:34 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int t;

	t = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		t = -n;
	}
	if (t / 10)
		ft_putnbr_fd(t / 10, fd);
	ft_putchar_fd('0' + t % 10, fd);
}
