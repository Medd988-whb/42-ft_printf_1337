/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:31:05 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 16:37:23 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_zero_prec(int width, int *count, t_flags flag)
{
	if (!flag.left_align)
	{
		while (width >= 0)
		{
			ft_putchar(' ', count);
			width--;
		}
		if (flag.plus)
			ft_putchar('+', count);
		else if (flag.space)
			ft_putchar(' ', count);
	}
	else
	{
		if (flag.plus)
			ft_putchar('+', count);
		else if (flag.space)
			ft_putchar(' ', count);
		while (width >= 0)
		{
			ft_putchar(' ', count);
			width--;
		}
	}
}

char	set_padding(t_flags flag)
{
	char	padding;

	padding = ' ';
	if (flag.precision >= 0)
		padding = ' ';
	else if (flag.zero_padding && !flag.left_align)
		padding = '0';
	return (padding);
}

void	ft_putnbr(int nb, int *count, t_flags flag)
{
	char	padding;
	int		len;
	int		width;
	int		precision;
	long	n;

	n = nb;
	len = handle_len_integer(n, flag);
	width = flag.width - len;
	if (n == 0 && flag.precision == 0)
		return (handle_zero_prec(width, count, flag));
	padding = set_padding(flag);
	if (!flag.left_align && padding == ' ' && width > 0)
		print_loop(padding, width, count);
	set_sign(n, count, flag);
	if (!flag.left_align && padding == '0' && width > 0)
		print_loop(padding, width, count);
	precision = flag.precision - ft_len_nb(n);
	if (precision > 0)
		print_loop('0', precision, count);
	print_nb(n, count);
	if (flag.left_align)
		print_loop(' ', width, count);
}
