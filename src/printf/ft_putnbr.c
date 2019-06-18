/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:09:26 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:23 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base(long long int n, int base, const char *digits)
{
	long long int	num;
	int				res;

	num = 0;
	res = 1;
	if (n < 0)
	{
		res++;
		num = (num + n) * -1;
	}
	else
		num = n;
	if (num >= base)
		res += ft_putnbr_base(num / base, base, digits);
	else if (num < 0)
		res += ft_putnbr_base(num / base * -1, base, digits);
	if (num < 0)
		write(1, &digits[num % base * -1], 1);
	else
		write(1, &digits[num % base], 1);
	return (res);
}

int		ft_putnbr(long long int n)
{
	return (ft_putnbr_base(n, 10, "0123456789"));
}
