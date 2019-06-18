/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex_long.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:59:46 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/05 13:20:11 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	intlen(unsigned long long n, int base)
{
	size_t len;

	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char			*ft_itoa_base_hex_long(unsigned long long n, int base, int uppercase)
{
	char	*res;
	long	len;
	char	*barr;

	if (n == 0)
		return (ft_strdup("0"));
	barr = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	len = intlen(n, base);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (len)
	{
		res[--len] = barr[(n % base)];
		n /= base;
	}
	return (res);
}
