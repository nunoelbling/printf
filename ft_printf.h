/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno1tap <nuno1tap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:15:42 by nuno1tap          #+#    #+#             */
/*   Updated: 2026/05/15 18:46:05 by nuno1tap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FT_PRINT_H
# define FT_PRINT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n, char *base);
int	ft_putptr(unsigned long ptr);
int	ft_puthex_long(unsigned long n, char *base);

#endif
