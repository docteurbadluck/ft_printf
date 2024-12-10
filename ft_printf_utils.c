/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:02:56 by tdeliot           #+#    #+#             */
/*   Updated: 2024/12/02 11:36:40 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	exeption_manager(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		g_count += 11;
		return (1);
	}
	return (0);
}

void	ft_putnbr(int n)
{
	char	digit;

	if (exeption_manager(n))
		return ;
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		g_count++;
		ft_putnbr(n);
	}
	else
	{
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
