/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/12 11:26:44 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_args(t_args *args, va_list ap)
{
	if (args->star == 1)
		args->width = va_arg(ap, int);
	else if (args->star == 2)
		args->precision = va_arg(ap, int);
	else if (args->star == 3)
	{
		args->width = va_arg(ap, int);
		args->precision = va_arg(ap, int);
	}
	if (args->width < 0)
	{
		args->width = args->width * -1;
		args->minus = 1;
		args->zero = 0;
	}
	if (args->precision < 0)
		args->precision = -1;
}

int	convert_type(t_args *args, va_list ap)
{
	int	count;

	count = 0;
	if (args->type == 'd' || args->type == 'i')
		count += ft_printf_d(args, ap);
	else if (args->type == 'x' || args->type == 'X')
		count += ft_printf_x(args, ap);
	else if (args->type == 'c')
		count += ft_printf_c(args, ap);
	else if (args->type == 's')
		count += ft_printf_s(args, ap);
	else if (args->type == 'p')
		count += ft_printf_p(args, ap);
	else if (args->type == 'u')
		count += ft_printf_u(args, ap);
	else if (args->type == '%')
		count += ft_printf_pct(args, ap);
	else
		args->len = 0;
	return (count);
}

int	padding(int n, char c)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += ft_putchar(c);
	return (count);
}
