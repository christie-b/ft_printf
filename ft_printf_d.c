/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/15 15:48:00 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_da(t_args *args, int len, unsigned long number)
{
	int	count;

	count = 0;
	if (args->neg_nb > 0)
	{
		args->precision++;
		count += ft_putchar('-');
	}
	count += padding(args->precision - len, '0') + ft_putnbr(number);
	return (count);
}

static int	ft_printf_db(t_args *args, int len, unsigned long number)
{
	int	count;

	count = 0;
	if (args->neg_nb > 0 && args->precision == -1)
	{
		args->precision++;
		if (args->zero)
			count += ft_putchar('-') + padding(args->width - len, '0');
		else
			count += padding(args->width - len, ' ') + ft_putchar('-');
		count += ft_putnbr(number);
	}
	else if (args->neg_nb > 0)
	{
		while ((args->precision >= 0) && (args->width-- - len))
			count += ft_putchar(' ');
		count += ft_putchar('-') + ft_putnbr(number);
	}
	else if (args->zero && args->precision == -1)
		count += padding(args->width - len, '0') + ft_putnbr(number);
	else
		count += padding(args->width - len, ' ') + ft_putnbr(number);
	return (count);
}

static int	ft_printf_dc(t_args *args, int len, unsigned long number)
{
	int	count;

	count = 0;
	if (args->neg_nb > 0)
		args->precision++;
	if (args->minus == 0)
		count += padding(args->width - args->precision, ' ');
	if (args->neg_nb > 0)
		count += ft_putchar('-');
	count += padding(args->precision - len, '0') + ft_putnbr(number);
	if (args->minus == 1)
		count += padding(args->width - args->precision, ' ');
	return (count);
}

static int	ft_printf_dd(t_args *args, int len, unsigned long number)
{
	int	count;

	count = 0;
	if (args->minus == 0)
		count += ft_printf_db(args, len, number);
	else if (args->neg_nb > 0 && args->zero > 0)
		count += ft_putchar('-') + padding(args->width - len, '0')
			+ ft_putnbr(number);
	else if (args->neg_nb > 0 && args->zero == 0)
		count += ft_putchar('-') + ft_putnbr(number)
			+ padding(args->width - len, ' ');
	else
		count += ft_putnbr(number) + padding(args->width - len, ' ');
	return (count);
}

int	ft_printf_d(t_args *args, va_list ap)
{
	long			nb;
	unsigned long	long_num;
	int				count;

	set_args(args, ap);
	nb = va_arg(ap, int);
	count = 0;
	if (nb < 0)
		args->neg_nb = 1;
	long_num = (unsigned long)(nb * (nb > 0) - nb * (nb < 0));
	if (args->precision == 0 && long_num == 0)
		count += padding(args->width, ' ');
	else if (args->precision >= numlen(nb) && args->precision >= args->width)
		count += ft_printf_da(args, numlen(nb), long_num);
	else if (args->width >= numlen(nb) && numlen(nb) > args->precision)
		count += ft_printf_dd(args, numlen(nb), long_num);
	else if (args->width > args->precision && args->precision >= numlen(nb))
		count += ft_printf_dc(args, numlen(nb), long_num);
	else if (args->neg_nb)
		count += ft_putchar('-') + ft_putnbr(long_num);
	else
		count += ft_putnbr(long_num);
	return (count);
}
