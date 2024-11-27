/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:47:51 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 11:28:42 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru(unsigned int n, int *count, t_flags flag)
{
	char	padding;
	int		len;
	int		width;
	int		precision;

	len = handle_len_integer(n, flag);
	width = flag.width - len;
	if (n == 0 && flag.precision == 0)
		return (handle_zero_prec(width, count, flag));
	padding = set_padding(flag);
	if (flag.zero_padding && padding == '0' && width > 0)
		print_loop(padding, width, count);
	set_sign(n, count, flag);
	if (!flag.left_align && width > 0 && padding == ' ')
		print_loop(padding, width, count);
	precision = flag.precision - ft_len_nb(n);
	if (precision > 0)
		print_loop('0', precision, count);
	print_nb(n, count);
	if (flag.left_align)
		print_loop(padding, width, count);
}
