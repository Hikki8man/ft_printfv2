/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:56:31 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/17 16:58:46 by jchevet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft.h"
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			dot;
	int 		width;
	int			precision;
	char 		conv;
}				t_flags;

int     ft_printf(const char *s, ...);

t_flags	init_struct(void);

int 	is_flag(char c);
int 	is_type(char c);
int 	flags_parsing(t_flags *flags, char *str,va_list varlist);
int 	is_valid(const char **str, t_flags *flags, va_list varlist);

int 	get_precision(char *str_flags, t_flags *flags, va_list varlist);
int		get_width(char *str_flag, t_flags *flags, va_list varlist);

int 	print(char c, va_list varlist, t_flags *flags);
int 	print_field(t_flags *flags);
int		print_precision(t_flags *flags);
int		print_str(va_list varlist, t_flags *flags);
int		print_char(va_list varlist, t_flags *flags);
int 	print_int(va_list var_list, t_flags *flags);
int 	print_uint(va_list varlist, t_flags *flags);
int 	print_hex(va_list varlist, t_flags *flags);
int 	print_p(va_list varlist, t_flags *flags);

#endif
