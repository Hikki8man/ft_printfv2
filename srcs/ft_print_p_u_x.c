//
// Created by Stellar on 18/12/2020.
//

#include "../include/ft_printf.h"

void 	field_sum(t_flags *flags, int *size)
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

int 	print_uint(va_list varlist, t_flags *flags)
{
	int 			size;
	unsigned int 	value;
	int				char_printed;
	char 			*to_print;

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
		ft_putstr_fd(to_print, 1);
	if (flags->minus)
		char_printed += print_field(flags);
	free(to_print);
	return (char_printed += size);
}

int 	print_hex(va_list varlist, t_flags *flags)
{
	int 	size;
	unsigned int 	value;
	int		char_printed;
	char 	*to_print;

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

int 	print_p(va_list varlist, t_flags *flags)
{
	int 	int_len;
	unsigned long long	int adress;
	int		char_printed;
	char 	*to_print;

	char_printed = 0;
	adress = va_arg(varlist, unsigned long long int);
	to_print = ft_ullitoa_base(adress, "0123456789abcdef");
	int_len = ft_strlen(to_print);
	if (!adress)
	{
		int_len = 0;
		flags->width -= 5;
		flags->precision = 0;
	}
	if (flags->precision > int_len){
		flags->width -= flags->precision;
		flags->precision -= int_len;
	}
	else
		flags->width -= int_len;
	if (adress)
		flags->width -= 2;

	if (!flags->minus)
		char_printed += print_field(flags);

	if (adress)
		char_printed += write(1, "0x", 2);
	char_printed += print_precision(flags);

	if (!adress)
		char_printed += (write(1, "(nil)", 5));
	else
		ft_putstr(to_print);

	if (flags->minus)
		char_printed += print_field(flags);
	free(to_print);
	return (char_printed + int_len);
}