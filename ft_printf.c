/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuelblin <nuelblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:46:49 by nuelblin          #+#    #+#             */
/*   Updated: 2026/05/21 14:41:52 by nuelblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char specifier, va_list args)
{
	int	len;

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

/* int	main(void)
{
	int	n = 42;

	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "42 Lisboa");
	ft_printf(" NULL %s NULL ", NULL);
	ft_printf("Pointer: %p\n", &n);
	ft_printf("Decimal: %d\n", -2147483648);
	ft_printf("Integer: %i\n", 2147483647);
	ft_printf("Unsigned: %u\n", 4294967295U);
	ft_printf("Hex Low: %x\n", 255);
	ft_printf("Hex Up: %X\n", 255);
	ft_printf("Percent: %%\n");
	return (0);
} */
