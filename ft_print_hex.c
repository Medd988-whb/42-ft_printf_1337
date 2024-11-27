/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:08 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 15:45:26 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_ox(unsigned int n, int hash, int cas, int *count)
{
	if (hash && n)
	{
		if (cas == 'x')
			ft_putstr("0x", 2, count);
		else if (cas == 'X')
			ft_putstr("0X", 2, count);
	}
}

void	ft_print_hex(unsigned int n, int cas, int *count)
{
	char	*basex;
	char	*basexx;

	basex = "0123456789abcdef";
	basexx = "0123456789ABCDEF";
	if (n < 16)
	{
		if (cas == 'x')
			ft_putchar(basex[n], count);
		else if (cas == 'X')
			ft_putchar(basexx[n], count);
	}
	else
	{
		ft_puthex(n / 16, cas, count, ft_initializ_flags());
		ft_puthex(n % 16, cas, count, ft_initializ_flags());
	}
}

char	ft_handle_padd(t_flags flag)
{
	char	padding;

	if (flag.precision >= 0)
		padding = ' ';
	else if (flag.zero_padding && !flag.left_align)
		padding = '0';
	else
		padding = ' ';
	return (padding);
}

void	ft_handle_zero_prec(unsigned int n, int width, int *count, t_flags flag)
{
	if (n == 0 && flag.precision == 0)
	{
		while (width >= 0)
		{
			ft_putchar(' ', count);
			width--;
		}
	}
}

void	ft_puthex(unsigned int n, int cas, int *count, t_flags flag)
{
	int		width;
	int		len;
	int		precision;
	char	padding;

	len = ft_handle_len_hex(n, flag);
	width = flag.width - len;
	if (n == 0 && flag.precision == 0)
		return (ft_handle_zero_prec(n, width, count, flag));
	padding = ft_handle_padd(flag);
	if (!flag.left_align && padding == ' ' && width > 0)
		print_loop(padding, width, count);
	handle_ox(n, flag.hash, cas, count);
	if (flag.zero_padding && padding == '0' && width > 0)
		print_loop(padding, width, count);
	precision = flag.precision - ft_len_hex(n);
	if (precision > 0)
		print_loop('0', precision, count);
	ft_print_hex(n, cas, count);
	if (flag.left_align)
		print_loop(padding, width, count);
}
