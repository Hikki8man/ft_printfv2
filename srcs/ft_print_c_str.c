//
// Created by Stellar on 18/12/2020.
//

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
	if (!str && (flags->dot == 0 || flags->precision > 6 || flags->precision == -1))
		len = 6;
	else
		len = ft_strlen(str);
	if (flags->precision == 0)
		len = 0;
	if (flags->precision < len && flags->precision > 0)
		len = flags->precision;
	flags->width -= len;
	if (!flags->minus)
		char_printed += print_field(flags);
	if (!str && (flags->dot == 0 || flags->precision > 6 || flags->precision == -1))
		char_printed += write(1, "(null)", 6);
	while (++i < len && str)
	{
		ft_putchar(str[i]);
		char_printed++;
	}
	if (flags->minus)
		char_printed += print_field(flags);
	return (char_printed);
}
