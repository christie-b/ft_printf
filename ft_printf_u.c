/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/15 13:01:48 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen_unsigned(unsigned int num)
{
	int	i;

	i = 1;
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 1;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + 48);
	return (count);
}

static int	ft_printf_ua(t_args *args, int len, int number)
{
	int	count;

	count = 0;
	if (args->minus == 0)
	{
		if (args->zero && args->precision == -1)
			count += padding(args->width - len, '0');
		else
			count += padding(args->width - len, ' ');
		count += ft_putnbr_unsigned(number);
	}
	else
		count += ft_putnbr_unsigned(number) + padding(args->width - len, ' ');
	return (count);
}

static int	ft_printf_ub(t_args *args, int len, int number)
{
	int	count;

	count = 0;
	if (args->minus == 0)
		count += padding(args->width - args->precision, ' ');
	count += padding(args->precision - len, '0');
	count += ft_putnbr_unsigned(number);
	if (args->minus == 1)
		count += padding(args->width - args->precision, ' ');
	return (count);
}

int	ft_printf_u(t_args *args, va_list ap)
{
	int				count;
	int				len;
	unsigned int	number;

	set_args(args, ap);
	number = va_arg(ap, unsigned long);
	count = 0;
	len = numlen_unsigned(number);
	if (args->precision == 0 && number == 0)
		count += padding(args->width, ' ');
	else if (args->len == 0 || (len >= args->width && len >= args->precision))
		count += ft_putnbr_unsigned(number);
	else if (args->precision > len && args->precision >= args->width)
		count += padding(args->precision - len, '0')
			+ ft_putnbr_unsigned(number);
	else if (args->width >= len && len > args->precision)
		count += ft_printf_ua(args, len, number);
	else if (args->width > args->precision && args->precision >= len)
		count += ft_printf_ub(args, len, number);
	return (count);
}
