/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:15:51 by cboutier          #+#    #+#             */
/*   Updated: 2021/06/15 13:14:01 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_args *args)
{
	args->minus = 0;
	args->zero = 0;
	args->star = 0;
	args->precision = -1;
	args->width = 0;
	args->len = 0;
	args->type = '\0';
	args->neg_nb = 0;
}

void	checkflag(const char c, t_args *args)
{
	if (c == '-')
	{
		args->minus = 1;
		args->zero = 0;
	}
	if (c == '0' && args->minus != 1 && args->width == 0)
		args->zero = 1;
	if (c == '.' && args->precision == -1)
		args->precision = 0;
	if (c == '*')
	{
		if (args->precision == -1)
			args->star = 1;
		else
		{
			if (args->star == 0)
				args->star = 2;
			else
				args->star = 3;
		}
	}
}

void	find_type(t_args *args, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 's' || str[i] == 'c' || str[i] == 'd' || str[i] == 'i'
			|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'p'
			|| str[i] == '%')
		{
			args->type = str[i];
			break ;
		}
		i++;
	}
}

int	readflag(t_args *args, const char *str)
{
	int	i;

	i = 0;
	find_type(args, str);
	while (str[i] == '-' || str[i] == '*' || str[i] == '.' || isdigit(str[i]))
	{
		checkflag(str[i], args);
		if (isdigit(str[i]))
		{
			while (isdigit(str[i]))
			{
				if (args->precision == -1)
					args->width = args->width * 10 + str[i] - '0';
				if (args->precision >= 0)
					args->precision = args->precision * 10 + str[i] - '0';
				i++;
			}
		}
		else
			i++;
		while (args->precision == 0 && str[i] == '0')
			i++;
	}
	args->len = i;
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;
	t_args	args;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			init(&args);
			str++;
			readflag(&args, str);
			count += convert_type(&args, ap);
			str = str + args.len;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}
