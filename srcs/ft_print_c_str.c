/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:37:46 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/19 17:37:46 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_char(va_list varlist, t_flags *flags)
{
	int		char_printed;
	char c;

	char_printed = 0;
	flags->zero = 0;
	flags->width -= 1;
	c = (char)va_arg(varlist, int);
	if (!flags->minus)
		char_printed += print_field(flags);
	ft_putchar(c);
	if (flags->minus)
		char_printed += print_field(flags);
	return (char_printed + 1);
}

int		print_str(va_list varlist, t_flags *flags)
{
	char 	*str;
	int 	char_printed;
	int		len;
	int		i;

	i = -1;
	char_printed = 0;
	flags->zero = 0;
	str = (char *)va_arg(varlist, char *);
	if (!str)
	{
		str = ft_strdup("(null)");
		len = 6;
	}
	else
		len = ft_strlen(str);
	if (flags->precision == 0)
		len = 0;
	if (flags->precision < len && flags->precision > 0)
		len = flags->precision;
	flags->width -= len;
	if (!flags->minus)
		char_printed += print_field(flags);
	while (++i < len)
	{
		ft_putchar(str[i]);
		char_printed++;
	}
	if (flags->minus)
		char_printed += print_field(flags);
	return (char_printed);
}
