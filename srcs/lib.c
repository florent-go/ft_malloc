#include "../include/malloc.h"

void ft_bzero(void *s, size_t n)
{
    char *str;

    str = (char *)s;
    while (n--)
        str[n] = 0;
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    char *dst_str;
    char *src_str;

    dst_str = (char *)dst;
    src_str = (char *)src;

    if (dst == src)
        return dst;
    
    while (n--)
    {
        *dst_str++ = *src_str++;
    }
    return dst;
}

void *ft_memset(void *b, int c, size_t len)
{
    size_t          i;
    unsigned char   *str;

    i = 0;
    str = (unsigned char *)b;
    while (i < len)
    {
        str[i] = (unsigned char)c;
        i++;
    }
    return (b);
}

void ft_putstr(char const *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    write(1, s, i);
}

void ft_itoa_base(size_t nb, char base, char lenght, bool prefixe)
{
    char *str;

    str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (nb/base)
        ft_itoa_base(nb/base, base,lenght-1, prefixe);
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