/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:10:49 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 11:20:42 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_nb(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	handle_len_integer(long n, t_flags flag)
{
	int	len;

	len = ft_len_nb(n);
	if (flag.precision > len)
		len = flag.precision;
	if (flag.plus || flag.space || (n < 0))
		len++;
	return (len);
}

void	print_loop(char c, int loop, int *count)
{
	while (loop-- > 0)
		ft_putchar(c, count);
}

void	set_sign(long n, int *count, t_flags flag)
{
	if ((n < 0))
		ft_putchar('-', count);
	else if (flag.plus)
		ft_putchar('+', count);
	else if (flag.space)
		ft_putchar(' ', count);
}

void	print_nb(long n, int *count)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		ft_putnbr(n / 10, count, ft_initializ_flags());
		ft_putchar((n % 10) + '0', count);
	}
	else
		ft_putchar(n + '0', count);
}
