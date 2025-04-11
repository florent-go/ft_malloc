#include "../includes/libft.h"

void    	ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}