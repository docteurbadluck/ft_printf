/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:34:28 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 15:39:04 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	int	size;

	if (!s)
	{
		write(1, "(null)", 6);
		g_count += 6;
		return ;
	}
	size = ft_strlen(s);
	write(1, s, size);
	g_count += size;
}

void	ft_putptr(unsigned long long ptr)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		g_count += 5;
	}
	else
	{
		write(1, "0x", 2);
		g_count += 2;
		ft_put_ptr(ptr);
	}
}

void	ft_put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}
