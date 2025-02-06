/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:03:18 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 13:26:45 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_count;

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
	return (g_count);
}

int main()
{
	ft_printf("%d %s %x",10, "abc",255);
	return 0; 
}
