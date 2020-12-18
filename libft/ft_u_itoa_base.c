/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:56:54 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/17 16:56:54 by jchevet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ulength(unsigned int n, int base_len)
{
	int				len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char 	*ft_u_itoa_base(unsigned int n, char *base)
{;
	char 			*to_ret;
	int				size;
	int 			base_len;


	base_len = ft_strlen(base);
	size = ft_ulength(n, base_len);
	if (!(to_ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	to_ret[size] = '\0';
	while (--size >= 0)
	{
		to_ret[size] = base[n % base_len];
		n /= base_len;
	}
	return (to_ret);
}
