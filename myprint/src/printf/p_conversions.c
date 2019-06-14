/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:55:31 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/12 14:33:29 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include "libft.h"

int		ft_pconversions(t_params ft, int str_len, char *num)
{
	int		tmp;
	long	res;

	res = 0;
	tmp = 0;
	if (!(ft.flags & MINUS_FLAG))
	{
		if ((tmp = fill_with_chars(ft.field_width - (ft.precision > str_len ?
			ft.precision : str_len), (ft.flags & ZERO_FLAG) ? '0' : ' ')) == -1)
			return (tmp);
		res += tmp;
	}
	if ((tmp = fill_with_chars(ft.precision - str_len, '0')) == -1)
		return (tmp);
	res += tmp;
	if ((tmp = write(1, num, str_len)) == -1)
		return (tmp);
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
	{
		if ((tmp = fill_with_chars(ft.field_width - ((ft.precision > str_len) ?
			ft.precision : str_len), ' ')) == -1)
			return (tmp);
		res += tmp;
	}
	return (res);
}

int		p_conversions(t_params ft, va_list *args, t_list **lst)
{
	long long int	arg_val;
	int				tmp;
	char			*num;
	char			*num2;
	int				str_len;

	arg_val = va_arg(*args, long long int);
	num = ft_itoa_base(arg_val, 16, 0);
	str_len = ft_strlen(num);
	num2 = "0x";
	num = ft_strjoin(num2, num);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
								ft.flags &= ~ZERO_FLAG : ft.flags;
	if ((tmp = ft_pconversions(ft, str_len + 2, num)) == -1)
		return (tmp);
	tmp += str_len + 2;
	return (tmp);
}
