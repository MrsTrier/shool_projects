/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:08:21 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/12 15:43:16 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "conversions.h"
#include "libft.h"
#include "ft_string.h"

// int		place_zero(char c, t_params ft, char hash)
// {
// 	int		tmp;

// 	tmp = 0;
// 	if (((ft.flags & ZERO_FLAG) ? '0' : ' ') == c)
// 	{
// 		if (hash)
// 		{
// 			if (ft.conversion == 'x')
// 			{
// 				if ((tmp = write(1, "0x", 2)) == -1)
// 					return (tmp);
// 			}
// 			else
// 			{
// 				if ((tmp = write(1, "0X", 2)) == -1)
// 					return (tmp);
// 			}
// 		}
// 	}
// 	return (tmp);
// }

int		place_space(t_params ft, int str_len, int *res, int hash)
{
	int tmp;

	tmp = 0;
	if (!(ft.flags & MINUS_FLAG))
	{
		if ((tmp = fill_with_chars(ft.field_width - (ft.precision > str_len ?
			ft.precision : str_len) - hash,
			(ft.flags & ZERO_FLAG) ? '0' : ' ')) == -1)
			return (tmp);
		*res += tmp;
	}
	// *res += place_zero(' ', ft, hash);
	if ((tmp = fill_with_chars(ft.precision - str_len - hash, '0')) == -1)
		return (tmp);
	*res += tmp;
	return (0);
}

int		ft_xconversions(t_params ft, int str_len, char *num)
{
	int		tmp;
	int		res;
	int		hash;

	res = 0;
	tmp = 0;
	hash = (ft.flags & HASH_FLAG) ? 2 : 0;
	// res += place_zero('0', ft, hash);
	place_space(ft, str_len, &res, hash);
	if ((tmp = write(1, num, str_len)) == -1)
		return (tmp);
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
	{
		if ((tmp = fill_with_chars(ft.field_width - ((ft.precision > str_len) ?
			ft.precision : str_len) - hash, ' ')) == -1)
			return (tmp);
		res += tmp;
	}
	return (res);
}

int		x_conversions(t_params ft, va_list *args, t_list **lst)
{
	long long	arg_val;
	int			tmp;
	char		*num;
	int			str_len;

	arg_val = convert_flags(ft.flags, args);
	if (ft.flags & l_FLAG || ft.flags & ll_FLAG)
		num = ft_itoa_base_hex_long(arg_val, 16,
		(ft.conversion == 'x') ? 0 : 1);
	else
		num = ft_itoa_base_hex(arg_val, 16, (ft.conversion == 'x') ? 0 : 1);
	(arg_val == 0) ? ft.flags &= ~HASH_FLAG : ft.flags;
	str_len = ((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_strlen(num);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
								ft.flags &= ~ZERO_FLAG : ft.flags;
	ft_before_num(ft, str_len, (ft.flags & HASH_FLAG) ? 2 : 0, lst);
	if ((tmp = ft_xconversions(ft, str_len, num)) == -1)
		return (tmp);
	tmp += str_len;
	return (tmp);
}
