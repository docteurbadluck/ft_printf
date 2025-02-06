/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:25:41 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/15 09:38:14 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

void	ft_putnbr_u(unsigned int n)
{
	char	digit;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		digit = n + '0';
		write(1, &digit, 1);
		g_count++;
	}
}

void	ft_manage_arg(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	if (c == '%')
		ft_putchar(c);
	if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int));
	if (c == 'c')
		ft_putchar((char)va_arg(args, int));
	if (c == 's')
		ft_putstr(va_arg(args, char *));
	if (c == 'x')
		ft_putnbr_to_hex_min(va_arg(args, unsigned int));
	if (c == 'X')
		ft_putnbr_to_hex_maj(va_arg(args, unsigned int));
	if (c == 'p')
		ft_putptr(va_arg(args, unsigned long long));
}
