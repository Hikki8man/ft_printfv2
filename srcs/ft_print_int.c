/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:37:55 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/19 17:37:55 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	int_field(t_flags *flags, int *size, int *value)
{
	if (flags->precision == 0 && *value == 0)
		*size = 0;
	if (flags->zero == 1 && *value < 0)
		write(1, "-", 1);
	if (flags->precision >= *size)
	{
		flags->width -= flags->precision;
		flags->precision -= *size;
		if (*value < 0)
		{
			flags->precision += 1;
			flags->width -= 1;
		}
	}
	else
	{
		flags->width -= *size;
		flags->precision = 0;
	}
}

int		print_int(va_list varlist, t_flags *flags)
{
	int		size;
	int		value;
	int		char_printed;
	char	*to_print;

	char_printed = 0;
	value = (int)va_arg(varlist, int);
	to_print = ft_itoa(value);
	size = ft_strlen(to_print);
	int_field(flags, &size, &value);
	if (!flags->minus)
		char_printed += print_field(flags);
	if (!flags->zero && value < 0)
		write(1, "-", 1);
	char_printed += print_precision(flags);
	if (size > 0)
	{
		if (value < 0)
			ft_putstr(to_print + 1);
		else
			ft_putstr(to_print);
	}
	if (flags->minus)
		char_printed += print_field(flags);
	free(to_print);
	return (char_printed + size);
}
