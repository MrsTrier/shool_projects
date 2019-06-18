/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:02:56 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/07 14:35:22 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_u(unsigned long long n)
{
	char	pr;
	int		res;

	res = 1;
	if (n >= 10)
	{
		res += ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
	{
		pr = '0' + n;
		write(1, &pr, 1);
	}
	return (res);
}
