/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:44 by tdeliot           #+#    #+#             */
/*   Updated: 2024/12/02 11:40:32 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

extern int		g_count;

//ft_printf_utils
void	ft_putnbr(int n);
void	ft_putnbr_u(unsigned int n);

//ft_printf_utils_2
void	ft_putchar(char c);
int		ft_strlen(const char *str);
void	ft_putstr( char *s);

//ft_printf.c
void	ft_manage_arg(char c, va_list args);
int		ft_printf(const char *text, ...);

#endif