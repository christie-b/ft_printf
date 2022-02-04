/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/14 15:55:45 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pct(t_args *args, va_list ap)
{
	int	count;

	set_args(args, ap);
	count = 0;
	if (args->minus)
		count += ft_putchar('%');
	if (args->zero)
		count += padding(args->width - 1, '0');
	else
		count += padding(args->width - 1, ' ');
	if (!args->minus)
		count += ft_putchar('%');
	return (count);
}
