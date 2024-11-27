/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:06:07 by mohaben-          #+#    #+#             */
/*   Updated: 2024/11/27 11:57:08 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	hash;
	int	plus;
	int	space;
	int	zero_padding;
	int	precision;
	int	width;
	int	left_align;
}	t_flags;

int		ft_printf(const char *str, ...);
void	ft_putchar_bns(char c, int *count, t_flags flag);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int len, int *count);
void	ft_putstr_bns(char *s, int *count, t_flags flag);
void	ft_putnbr(int n, int *count, t_flags flag);
void	ft_putnbru(unsigned int n, int *count, t_flags flag);
void	ft_puthex(unsigned int n, int cas, int *count, t_flags flag);
void	ft_putptr(void *ptr, int *count, t_flags flag);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
t_flags	ft_initializ_flags(void);
int		ft_len_hex(unsigned int n);
int		ft_handle_len_hex(unsigned int n, t_flags flag);
int		ft_len_nb(long n);
int		handle_len_integer(long n, t_flags flag);
void	print_loop(char c, int loop, int *count);
void	set_sign(long n, int *count, t_flags flag);
void	print_nb(long n, int *count);
void	handle_zero_prec(int width, int *count, t_flags flag);
char	set_padding(t_flags flag);

#endif