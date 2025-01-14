/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:03:18 by tdeliot           #+#    #+#             */
/*   Updated: 2024/12/02 11:39:59 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_count;  

void	ft_manage_arg(char c, va_list args)
{
	if (c == 'd' || c == 'i')
	{
		ft_putnbr(va_arg(args, int));
	}
	if (c == '%')
	{
		ft_putchar(c);
	}
	if (c == 'u')
	{
		ft_putnbr_u(va_arg(args, unsigned int));
	}
	if (c == 'c')
	{
		ft_putchar((char)va_arg(args, int));
	}
	if (c == 's')
	{
		ft_putstr(va_arg(args, char*));
	}
	if (c == 'x')
	{
		write(1,"0x", 2);
		g_count +=2;
		ft_putnbr_to_hex_min(va_arg(args, unsigned int));
	}
	if (c == 'X')
	{
		write(1,"0x", 2);
		g_count +=2;
		ft_putnbr_to_hex_maj(va_arg(args, unsigned int));
	}

	if (c == 'p')
	{
		ft_putptr(va_arg(args, unsigned long long));
	}
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		i;

	g_count = 0;
	i = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] != '%')
		{
			ft_putchar(text[i]);
		}
		else
		{
			ft_manage_arg(text[i + 1], args);
			i++;
		}
		i++;
	}
	return g_count;
}