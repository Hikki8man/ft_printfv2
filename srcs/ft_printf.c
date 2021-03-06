/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:55:15 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/19 17:53:52 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// TODO: fix wrong output with '%' and not a valid type
// TODO: handle errors, maybe add char_printed to prints functions to return -1 if fail

int		print(char c, va_list varlist, t_flags *flags)
{
	int char_printed;

	flags->conv = c;
	char_printed = 0;
	if (c == 'd' || c == 'i')
		char_printed = print_int(varlist, flags);
	else if (c == 's')
		char_printed = print_str(varlist, flags);
	else if (c == 'c')
		char_printed = print_char(varlist, flags);
	else if (c == 'u')
		char_printed = print_uint(varlist, flags);
	else if (c == 'x' || c == 'X')
		char_printed = print_hex(varlist, flags);
	else if (c == 'p')
		char_printed = print_p(varlist, flags);
	return (char_printed);
}

int		ft_printf(const char *str, ...)
{
	int		char_printed;
	t_flags	flags;
	va_list	var_list;

	char_printed = 0;
	if (!str)
		return (-1);
	va_start(var_list, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			flags = init_struct();
			if (is_valid(&str, &flags, var_list))
				char_printed += print(*str++, var_list, &flags);
			else
				char_printed += write(1, str++, 1);
		}
		else if (*str == '%' && *(str + 1) == '\0')
			return (-1);
		else
			char_printed += write(1, str++, 1);
	}
	va_end(var_list);
	return (char_printed);
}
