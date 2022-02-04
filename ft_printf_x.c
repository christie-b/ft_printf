/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/15 13:01:48 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen_hex(unsigned long int n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long int n, char type)
{
	char	*hexnumber;
	int		len;
	char	*base;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = numlen_hex(n);
	hexnumber = malloc((len + 1) * sizeof(*hexnumber));
	if (!hexnumber)
		return (NULL);
	hexnumber[len] = '\0';
	while (len--)
	{
		hexnumber[len] = base[n % 16];
		n /= 16;
	}
	return (hexnumber);
}

static int	ft_printf_xa(t_args *args, int len, char *number)
{
	int	count;

	count = 0;
	if (args->minus == 0 && args->zero == 1 && args->precision == -1)
		count += padding(args->width - len, '0');
	else if (args->minus == 0 && args->zero == 1)
		count += padding(args->width - len, ' ');
	else if (args->minus == 0 && args->zero == 0)
		count += padding(args->width - len, ' ');
	count += ft_printf(number);
	if (args->minus == 1)
		count += padding(args->width - len, ' ');
	return (count);
}

static int	ft_printf_xb(t_args *args, int len, char *number)
{
	int	count;

	count = 0;
	if (args->minus == 0)
		count += padding(args->width - args->precision, ' ');
	count += padding(args->precision - len, '0');
	count += ft_printf(number);
	if (args->minus == 1)
		count += padding(args->width - args->precision, ' ');
	return (count);
}

int	ft_printf_x(t_args *args, va_list ap)
{
	int		count;
	int		nb;
	int		len;
	char	*number;

	set_args(args, ap);
	nb = va_arg(ap, int);
	number = ft_itoa_base((unsigned int)nb, args->type);
	count = 0;
	len = ft_strlen(number);
	if (args->precision == 0 && nb == 0)
		count += padding(args->width, ' ');
	else if (args->len == 0 || (len >= args->width && len >= args->precision))
		count += ft_printf(number);
	else if (args->precision > len && args->precision >= args->width)
		count += padding(args->precision - len, '0') + ft_printf(number);
	else if (args->width >= len && len > args->precision)
		count += ft_printf_xa(args, len, number);
	else if (args->width > args->precision && args->precision >= len)
		count += ft_printf_xb(args, len, number);
	free(number);
	return (count);
}
