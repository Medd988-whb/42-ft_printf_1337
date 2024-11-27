/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:44:18 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 11:56:50 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_handle_len_hex(unsigned int n, t_flags flag)
{
	int	len;

	len = ft_len_hex(n);
	if (flag.precision > len)
		len = flag.precision;
	if (flag.hash && n)
		len += 2;
	return (len);
}
