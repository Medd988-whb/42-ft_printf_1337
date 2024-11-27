/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:06:00 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 14:57:54 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	return (c == '#' || c == '+' || c == ' ' || c == '-' || c == '0');
}

t_flags	handle_prec_wid(const char **format, t_flags flag)
{
	if (**format >= '0' && **format <= '9')
	{
		flag.width = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	while (**format == '.')
	{
		(*format)++;
		flag.precision = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	return (flag);
}

t_flags	ft_set_flags(const char **format)
{
	t_flags	flag;

	flag = ft_initializ_flags();
	while (is_flag(**format))
	{
		if (**format == '#')
			flag.hash = 1;
		else if (**format == '+')
			flag.plus = 1;
		else if (**format == ' ')
			flag.space = 1;
		else if (**format == '-')
			flag.left_align = 1;
		else if (**format == '0')
			flag.zero_padding = 1;
		(*format)++;
	}
	flag = handle_prec_wid(format, flag);
	return (flag);
}

void	ft_print_format(const char **format, va_list ap, int *count)
{
	t_flags	flag;

	flag = ft_set_flags(format);
	if (**format == '%')
		ft_putchar_bns('%', count, flag);
	else if (**format == 'c')
		ft_putchar_bns(va_arg(ap, int), count, flag);
	else if (**format == 's')
		ft_putstr_bns(va_arg(ap, char *), count, flag);
	else if (**format == 'd' || **format == 'i')
		ft_putnbr(va_arg(ap, int), count, flag);
	else if (**format == 'u')
		ft_putnbru(va_arg(ap, unsigned int), count, flag);
	else if (**format == 'p')
		ft_putptr(va_arg(ap, void *), count, flag);
	else if (**format == 'x')
		ft_puthex(va_arg(ap, unsigned int), 'x', count, flag);
	else if (**format == 'X')
		ft_puthex(va_arg(ap, unsigned int), 'X', count, flag);
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	t_flags	flag;

	count = 0;
	flag = ft_initializ_flags();
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format != '\0')
				ft_print_format(&format, ap, &count);
			else
				format--;
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(ap);
	return (count);
}
