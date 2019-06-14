/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex..c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:34:08 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/12 17:19:22 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	intlen(unsigned int n, int base)
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

char			*ft_itoa_base_hex(unsigned int n, int base, int uppercase)
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
	res[--len] = '\0';
	while (len >= 0)
	{
		res[len] = barr[(n % base)];
		n /= base;
		len--;
	}
	return (res);
}
