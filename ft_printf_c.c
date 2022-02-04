/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:23 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/14 09:37:12 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(t_args *args, va_list ap)
{
	int		count;
	char	c;

	set_args(args, ap);
	c = va_arg(ap, int);
	count = 0;
	if (args->minus == 1)
		count = ft_putchar(c) + padding(args->width - 1, ' ');
	else
		count = padding(args->width - 1, ' ') + ft_putchar(c);
	return (count);
}
