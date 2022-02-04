/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/15 13:14:00 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_args
{
	int		minus;
	int		zero;
	int		star;
	int		precision;
	int		width;
	int		len;
	char	type;
	int		neg_nb;
}	t_args;

int		ft_printf(const char *str, ...);
int		padding(int n, char c);
int		isdigit(int c);
int		ft_putnbr(unsigned long n);
int		numlen(int num);
int		ft_strlen(char *s);
int		ft_putchar(char c);
void	init(t_args *args);
void	checkflag(const char c, t_args *args);
int		readflag(t_args *args, const char *str);
int		convert_type(t_args *args, va_list ap);
char	*ft_itoa_base(unsigned long int n, char type);
int		ft_printf_d(t_args *args, va_list ap);
int		ft_printf_c(t_args *args, va_list ap);
int		ft_printf_s(t_args *args, va_list ap);
int		ft_printf_x(t_args *args, va_list ap);
int		ft_printf_u(t_args *args, va_list ap);
int		ft_printf_p(t_args *args, va_list ap);
int		ft_printf_pct(t_args *args, va_list ap);
void	set_args(t_args *args, va_list ap);

#endif