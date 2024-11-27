/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:25:02 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 16:54:52 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putchar_bns(char c, int *count, t_flags flag)
{
	int		width;
	char	padding;

	width = flag.width - 1;
	padding = ' ';
	if (flag.zero_padding && !flag.left_align)
		padding = '0';
	if (flag.left_align)
	{
		ft_putchar(c, count);
		print_loop(padding, width, count);
	}
	else
	{
		print_loop(padding, width, count);
		ft_putchar(c, count);
	}
}

void	ft_putstr(char *s, int len, int *count)
{
	while (*s && len)
	{
		ft_putchar(*s, count);
		s++;
		len--;
	}
}

void	ft_putstr_bns(char *s, int *count, t_flags flag)
{
	int		width;
	int		len;
	char	padding;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (flag.precision >= 0 && len > flag.precision)
		len = flag.precision;
	width = flag.width - len;
	padding = ' ';
	if (flag.zero_padding && !flag.left_align)
		padding = '0';
	if (flag.left_align)
	{
		ft_putstr(s, len, count);
		print_loop(padding, width, count);
	}
	else
	{
		print_loop(padding, width, count);
		ft_putstr(s, len, count);
	}
}
