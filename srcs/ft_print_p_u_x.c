/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_u_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:38:20 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/19 17:38:20 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	field_sum(t_flags *flags, int *size)
{
	if (flags->precision >= *size)
	{
		flags->width -= flags->precision;
		flags->precision -= *size;
	}
	else
	{
		flags->width -= *size;
		flags->precision = 0;
	}
}

int		print_uint(va_list varlist, t_flags *flags)
{
	unsigned int	value;
	int				size;
	int				char_printed;
	char			*to_print;

	char_printed = 0;
	value = (unsigned int)va_arg(varlist, unsigned int);
	to_print = ft_u_itoa(value);
	size = ft_strlen(to_print);
	if (flags->precision == 0 && value == 0)
		size = 0;
	field_sum(flags, &size);
	if (!flags->minus)
		char_printed += print_field(flags);
	char_printed += print_precision(flags);
	if (size > 0)
		ft_putstr(to_print);
	if (flags->minus)
		char_printed += print_field(flags);
	free(to_print);
	return (char_printed += size);
}

int		print_hex(va_list varlist, t_flags *flags)
{
	unsigned int	value;
	int				size;
	int				char_printed;
	char			*to_print;

	char_printed = 0;
	value = (unsigned int)va_arg(varlist, unsigned int);
	if (flags->conv == 'x')
		to_print = ft_u_itoa_base(value, "0123456789abcdef");
	else
		to_print = ft_u_itoa_base(value, "0123456789ABCDEF");
	size = ft_strlen(to_print);
	if (value == 0 && flags->precision == 0)
		size = 0;
	field_sum(flags, &size);
	if (!flags->minus)
		char_printed += print_field(flags);
	char_printed += print_precision(flags);
	if (size > 0)
		ft_putstr_fd(to_print, 1);
	if (flags->minus)
		char_printed += print_field(flags);
	free(to_print);
	return (char_printed += size);
}

int		print_p(va_list varlist, t_flags *flags)
{
	unsigned long long	int	value;
	int						size;
	int						char_printed;
	char					*to_print;

	char_printed = 0;
	value = va_arg(varlist, unsigned long long int);
	to_print = ft_ullitoa_base(value, "0123456789abcdef");
	size = ft_strlen(to_print);
	flags->width -= 2;
	field_sum(flags, &size);
	if (!flags->minus)
		char_printed += print_field(flags);
	char_printed += write(1, "0x", 2);
	char_printed += print_precision(flags);
	ft_putstr(to_print);
	if (flags->minus)
		char_printed += print_field(flags);
	free(to_print);
	return (char_printed + size);
}
