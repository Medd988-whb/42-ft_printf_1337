/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:15:20 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 16:13:47 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_putptrhex(unsigned long n, int *count)
{
	char	*basex;

	basex = "0123456789abcdef";
	if (n < 16)
		ft_putchar(basex[n], count);
	else
	{
		ft_putptrhex(n / 16, count);
		ft_putptrhex(n % 16, count);
	}
}

void	ft_putptr(void *ptr, int *count, t_flags flag)
{
	unsigned long	p;
	int				width;
	int				len;

	if (ptr == NULL)
		return (ft_putstr_bns("0x0", count, flag));
	p = (unsigned long)ptr;
	len = ft_len_ptr(p) + 2;
	width = flag.width - len;
	if (!flag.left_align)
		print_loop(' ', width, count);
	ft_putstr("0x", 2, count);
	ft_putptrhex(p, count);
	if (flag.left_align)
		print_loop(' ', width, count);
}
