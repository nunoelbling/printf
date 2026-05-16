/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuelblin <nuelblin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:43:15 by nuelblin          #+#    #+#             */
/*   Updated: 2026/05/16 14:52:34 by nuelblin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	int	len;

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
