/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno1tap <nuno1tap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:46:49 by nuno1tap          #+#    #+#             */
/*   Updated: 2026/05/15 19:07:35 by nuno1tap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_format(char specifier, va_list args)
{
    int len;

    len = 0;
    if (specifier == 'c')
        len += ft_putchar(va_arg(args, int));
    else if (specifier == 's')
        len += ft_putstr(va_arg(args, char *));
    else if (specifier == 'p')
        len += ft_putptr(va_arg(args, unsigned long));
    else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		len += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		len += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (specifier == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	i = 0;
	total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			total_len += ft_check_format(format[i + 1], args);
			i++;
		}
		else
			total_len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (total_len);
}