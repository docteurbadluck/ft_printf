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
	if (c == 'd')
	{
		ft_putnbr(va_arg(args, int));
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
			g_count++;
		}
		else
		{
			ft_manage_arg(text[i + 1], args);
			i++;
		}
		i++;
	}
}

void	test_ft_putnbr_u()
{

    // Test case 1: Smallest possible unsigned integer
    ft_putnbr_u(0);
    write(1, "\n", 1);  // Output a newline
    ft_putnbr_u(5);
    write(1, "\n", 1);

    // Test case 3: Two-digit unsigned integer
    ft_putnbr_u(42);
    write(1, "\n", 1);
    // Test case 4: Three-digit unsigned integer
    ft_putnbr_u(123);
    write(1, "\n", 1);
    // Test case 5: Larger unsigned integer
    ft_putnbr_u(9876);
    write(1, "\n", 1);
    // Test case 6: Maximum value of unsigned int (32-bit)
    ft_putnbr_u(4294967295);
    write(1, "\n", 1);
    // Test case 7: Random large unsigned integer
    ft_putnbr_u(1234567890);
    write(1, "\n", 1);

    ft_putnbr_u(654321);
    write(1, "\n", 1);

	return;
}



int main()
{
	/*
	 ft_printf("afsd %d %d", 151, 5 , 45 ,1, 5,4 ,0);
	printf("g_count = %d", g_count);*/
	test_ft_putnbr_u();
	return 0;
}