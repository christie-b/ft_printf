/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/14 12:13:45 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_pa(t_args *args)
{
	int	count;

	count = 0;
	if (args->minus)
	{
		count += ft_printf("0x");
		while (args->width-- - 2 > 0)
			count += ft_putchar(' ');
		return (count);
	}
	else
	{
		while (args->width-- - 2 > 0)
			count += ft_putchar(' ');
		count += ft_printf("0x");
		return (count);
	}
}

static int	ft_printf_pb(t_args *args, int len, char *end_hex)
{
	int	count;

	count = ft_printf("0x");
	while (args->precision-- - len)
		count += ft_putchar('0');
	count += ft_printf(end_hex);
	return (count);
}

static int	ft_printf_pc(t_args *args, int len, char *end_hex)
{
	int	count;
	int	pad_size;

	count = 0;
	len = len + 2;
	pad_size = args->width - len;
	if (!args->minus)
	{
		if (args->zero)
			count += padding(pad_size, '0');
		else
			count += padding(pad_size, ' ');
	}
	count += ft_printf("0x%s", end_hex);
	if (args->minus)
		count += padding(pad_size, ' ');
	return (count);
}

static int	ft_printf_pd(t_args *args, int len, char *end_hex)
{
	int	count;
	int	pad_size;

	count = 0;
	pad_size = args->width - args->precision;
	if (!args->minus)
		count += padding(pad_size, ' ');
	count += ft_printf("0x") + padding(args->precision - len, '0')
		+ ft_printf(end_hex);
	if (args->minus)
		count += padding(pad_size, ' ');
	return (count);
}

int	ft_printf_p(t_args *args, va_list ap)
{
	int					count;
	int					len;
	char				*end_hex;
	unsigned long int	end_dec;

	set_args(args, ap);
	end_dec = va_arg(ap, unsigned long int);
	end_hex = ft_itoa_base(end_dec, 'x');
	count = 0;
	len = ft_strlen(end_hex);
	if (args->precision == 0 && end_dec == 0)
		count += ft_printf_pa(args);
	else if (args->len == 0 || (len >= args->width && len >= args->precision))
		count += ft_printf("0x%s", end_hex);
	else if (args->precision > len && args->precision >= args->width)
		count += ft_printf_pb(args, len, end_hex);
	else if (args->width >= len && len > args->precision)
		count += ft_printf_pc(args, len, end_hex);
	else if (args->width > args->precision && args->precision >= len)
		count += ft_printf_pd(args, len, end_hex);
	free(end_hex);
	return (count);
}
