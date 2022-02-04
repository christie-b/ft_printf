/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/14 15:37:42 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_size(t_args *args, char *str)
{
	int	size;

	size = 0;
	if (args->precision > ft_strlen(str) || args->precision == -1)
		size = ft_strlen(str);
	else
		size = args->precision;
	return (size);
}

int	ft_printf_s(t_args *args, va_list ap)
{
	int		count;
	char	*str;
	int		size;
	int		pad_size;

	set_args(args, ap);
	str = va_arg(ap, char *);
	count = 0;
	if (args->precision == 0 && args->width == 0)
		return (0);
	if (str == NULL)
		str = "(null)";
	size = set_size(args, str);
	pad_size = args->width - size;
	if (!args->minus && args->zero)
		count += padding(pad_size, '0');
	else if (!args->minus)
		count += padding(pad_size, ' ');
	while (size-- && *str)
		count += ft_putchar(*str++);
	if (args->minus)
		count += padding(pad_size, ' ');
	return (count);
}
