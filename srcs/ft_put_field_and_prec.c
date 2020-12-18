//
// Created by Stellar on 18/12/2020.
//

#include "../include/ft_printf.h"

int 	print_field(t_flags *flags)
{
	int char_printed;

	char_printed = 0;
	if (flags->zero == 1)
	{
		while (char_printed < flags->width)
		{
			write (1, "0", 1);
			char_printed++;
		}
	}
	else
	{
		while (char_printed < flags->width)
		{
			write(1, " ", 1);
			char_printed++;
		}
	}
	return (char_printed);
}

int		print_precision(t_flags *flags)
{
	int i;

	i = 0;
	while (i < flags->precision)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}