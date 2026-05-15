/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno1tap <nuno1tap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:26:38 by nuno1tap          #+#    #+#             */
/*   Updated: 2026/05/15 19:15:49 by nuno1tap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)
{
    int i;
    
    i = 0;
    if (!s)
        return (ft_putstr("(null"));
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int n)
{
    int len;

    len = 0;
    if (n == -2147483648)
        return (ft_putstr("-2147483648"));
    if (n < 0)
    {
        len += ft_putchar('-');
        n *= -1; 
    }
    if (n > 9)
        len += ft_putnbr(n / 10);
    len += ft_putchar((n % 10) + '0');
    return (len);
}

int ft_putunsigned(unsigned int n)
{
    int len;
    
    len = 0;
    if (n > 9)
        len += ft_putunsigned(n / 10);
    len += ft_putchar((n % 10) + '0');
    return (len);
}

int ft_puthex(unsigned int n, char *base)
{
    int len;

    len = 0;
    if (n >= 16)
        len += ft_puthex(n / 16, base);
    len += ft_putchar(base[n % 16]);
    return (len);
}

int	ft_puthex_long(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_long(n / 16, base);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex_long(ptr, "0123456789abcdef");
	return (len);
}