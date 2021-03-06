/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:47:40 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/19 17:47:45 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		is_type(char c)
{
	return (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'u' ||
	c == 'p' || c == 'x' || c == 'X');
}

int		is_flag(char c)
{
	return (c == '-' || (c >= '0' && c <= '9') || c == '.' || c == '*' ||
	c == '%');
}

t_flags	init_struct(void)
{
	t_flags flags;

	flags.zero = 0;
	flags.dot = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.conv = ' ';
	return (flags);
}

int		is_valid(const char **str, t_flags *flags, va_list varlist)
{
	char	*str_flags;
	int		i;

	str_flags = (char *)*str;
	i = 0;
	if (*(str_flags + 1) == '%')
	{
		*str += 1;
		return (0);
	}
	while (is_flag(*(str_flags + i)))
		i++;
	if (!is_type(*(str_flags + i)))
		return (0);
	*str += i;
	str_flags = ft_substr(str_flags, 0, i);
	flags_parsing(flags, str_flags, varlist, i);
	free(str_flags);
	return (1);
}

int		flags_parsing(t_flags *flags, char *str_flags, va_list varlist, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		if (str_flags[i] >= '1' && str_flags[i] <= '9')
			i += get_width(str_flags + i, flags, varlist);
		else if (str_flags[i] == '*')
			get_width(str_flags + i, flags, varlist);
		else if (str_flags[i] == '.')
		{
			flags->dot = 1;
			flags->precision = 0;
			if (str_flags[i + 1] == '*' || ft_isdigit(str_flags[i + 1]))
				i += get_precision(str_flags + i + 1, flags, varlist);
		}
		else if (str_flags[i] == '0')
			flags->zero = 1;
		else if (str_flags[i] == '-')
			flags->minus = 1;
		i++;
	}
	if (flags->zero && (flags->minus || (flags->dot && flags->precision != -1)))
		flags->zero = 0;
	return (1);
}
