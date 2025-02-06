/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:02:56 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/14 13:25:05 by tdeliot          ###   ########.fr       */
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

//coppy into another buffer, use the dstsize to don't overflow.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_putnbr_to_hex_maj(unsigned int n)
{
	char	str[17];
	char	digit;

	ft_strlcpy(str, "0123456789ABCDEF", 17);
	if (n > 15)
	{
		ft_putnbr_to_hex_maj(n / 16);
		ft_putnbr_to_hex_maj(n % 16);
	}
	else
	{
		digit = str[n];
		write(1, &digit, 1);
		g_count++;
	}
}

void	ft_putnbr_to_hex_min(unsigned int n)
{
	char	str[17];
	char	digit;

	ft_strlcpy(str, "0123456789abcdef", 17);
	if (n > 15)
	{
		ft_putnbr_to_hex_min(n / 16);
		ft_putnbr_to_hex_min(n % 16);
	}
	else
	{
		digit = str[n];
		write(1, &digit, 1);
		g_count++;
	}
}
